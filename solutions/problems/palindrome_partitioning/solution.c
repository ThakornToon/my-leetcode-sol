/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool check_pa(char* s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void backtrack(char* s, char*** ans, char** store, int start, int* returnSize, int** returnColumnSizes, int count) {
    if (start == strlen(s)) {
        ans[*returnSize] = (char**)malloc(count * sizeof(char*));
        for (int i = 0; i < count; i++) {
            ans[*returnSize][i] = strdup(store[i]);
        }
        (*returnColumnSizes)[*returnSize] = count;
        (*returnSize)++;
        return;
    }
    for (int end = start; end < strlen(s); end++) {
        if (check_pa(s, start, end)) {
            char* sub = (char*)malloc((end - start + 2) * sizeof(char));
            strncpy(sub, s + start, end - start + 1);
            sub[end - start + 1] = '\0';
            store[count] = sub;
            backtrack(s, ans, store, end + 1, returnSize, returnColumnSizes, count + 1);
            free(store[count]);
            store[count] = NULL;
        }
    }
    return;
}
char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    char*** ans = (char***)malloc(32768 * sizeof(char**));
    char** store = (char**)malloc(strlen(s) * sizeof(char*));
    *returnColumnSizes = (int*)malloc(32768 * sizeof(int));
    *returnSize = 0;
    int count = 0;
    backtrack(s, ans, store, 0, returnSize, returnColumnSizes, count);
    ans = (char***)realloc(ans, (*returnSize) * sizeof(char**));
    *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*returnSize) * sizeof(int));
    free(store);
    return ans;
}