/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(char* num, int idx, long long target, char** ans, char* curr, long long val, long long multed, int* returnSize) {
    if (idx == strlen(num)) {
        if (val == target) {
            ans[(*returnSize)++] = strdup(curr);
        }
        return;
    }

    for (int i = idx; i < strlen(num); i++) {
        // หลีกเลี่ยงเลขนำด้วย 0 เช่น "05"
        if (i != idx && num[idx] == '0') {
            break;
        }
        char numStr[11];
        strncpy(numStr, num + idx, i - idx + 1);
        numStr[i - idx + 1] = '\0';
        long long currNum = strtoll(numStr, NULL, 10);
        int sign = strlen(curr);
        if (idx == 0) {
            strcat(curr, numStr);
            backtrack(num, i + 1, target, ans, curr, currNum, currNum, returnSize);
        } else {
            // การบวก
            curr[sign] = '+';
            curr[sign + 1] = '\0';
            strcat(curr, numStr);
            backtrack(num, i + 1, target, ans, curr, val + currNum, currNum, returnSize);

            // การลบ
            curr[sign] = '-';
            backtrack(num, i + 1, target, ans, curr, val - currNum, -currNum, returnSize);

            // การคูณ - ตรวจสอบ overflow ก่อนคำนวณ
            if (multed == 0 || (currNum <= LLONG_MAX / abs(multed))) {
                long long newMulted = multed * currNum;
                curr[sign] = '*';
                backtrack(num, i + 1, target, ans, curr, val - multed + newMulted, newMulted, returnSize);
            }
        }
        curr[sign] = '\0';
    }
}
char** addOperators(char* num, int target, int* returnSize) {
    char** ans = (char**)malloc(5000 * sizeof(char*));
    *returnSize = 0;
    char curr[21] = ""; 
    backtrack(num, 0, (long long)target, ans, curr, 0, 0, returnSize);

    return ans;
}