/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool check(char* s) {
    int n = strlen(s);
    if (n == 1) {
        return true;
    }
    if (s[0] == '0') {
        return false;
    }
    int num = atoi(s);
    if (num > 255) {
        return false;
    }
    return true;
}

char** restoreIpAddresses(char* s, int* returnSize) {
    int n = strlen(s);
    char** ans = (char**)malloc(40 * sizeof(char*));
    *returnSize = 0;
    if (n > 12) {
        ans = (char**)realloc(ans, 0);
        return ans;
    }
    for (int d1 = 1; d1 <= 3; d1++) {
        for (int d2 = 1; d2 <= 3; d2++) {
            for (int d3 = 1; d3 <= 3; d3++) {
                if (d1 + d2 + d3 < n && d1 + d2 + d3 + 3 >= n) {
                    char p1[4];
                    strncpy(p1, s, d1);
                    p1[d1] = '\0';
                    char p2[4];
                    strncpy(p2, s + d1, d2);
                    p2[d2] = '\0';
                    char p3[4];
                    strncpy(p3, s + d1 + d2, d3);
                    p3[d3] = '\0';
                    int d4 = n - d1 - d2 - d3;
                    char p4[4];
                    strncpy(p4, s + d1 + d2 + d3, d4);
                    p4[d4] = '\0';

                    if (check(p1) && check(p2) && check(p3) && check(p4)) {
                        char* ip = (char*)malloc(d1 + d2 + d3 + d4 + 3 + 1);
                        sprintf(ip, "%s.%s.%s.%s", p1, p2, p3, p4);
                        ans[*returnSize] = ip;
                        (*returnSize)++;
                    }
                }
            }
        }
    }
    ans = (char**)realloc(ans, (*returnSize) * sizeof(char*));
    return ans;
}