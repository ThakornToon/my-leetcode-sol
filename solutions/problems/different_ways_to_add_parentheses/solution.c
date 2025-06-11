/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cal(int num1, int num2, char sign) {
    if (sign == '+') {
        return num1 + num2;
    } else if (sign == '-') {
        return num1 - num2;
    } else {
        return num1 * num2;
    }
}
int* findall(char* exp, int start, int end, int* totalSize) {
    int* all = NULL;
    *totalSize = 0;
    for (int i = start; i <= end; i++) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
            int lSize, rSize;
            int* left = findall(exp, start, i - 1, &lSize);
            int* right = findall(exp, i + 1, end, &rSize);
            all = (int*)realloc(all, (*totalSize + (lSize * rSize)) * sizeof(int));
            for (int j = 0; j < lSize; j++) {
                for (int k = 0; k < rSize; k++) {
                    all[(*totalSize)++] = cal(left[j], right[k], exp[i]);
                }
            }
            free(left);
            free(right);
        }
    }

    if (*totalSize == 0) {
        all = (int*)malloc(sizeof(int));
        int num = 0;
        for (int i = start; i <= end; i++) {
            num = (num * 10) + (exp[i] - '0');
        }
        all[(*totalSize)++] = num;
    }

    return all;
}
int* diffWaysToCompute(char* expression, int* returnSize) {
    return findall(expression, 0, strlen(expression) - 1, returnSize);
}