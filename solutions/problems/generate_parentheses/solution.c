/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** res = NULL;
void dfs(int open, int close, char* s, int n, int* returnSize) {
    if (open == n && close == n) {
        s[open+close] = '\0';
        (*returnSize)++;
        res = (char**)realloc(res, sizeof(char*) * (*returnSize));
        //res[(*returnSize)-1] = (char*)malloc(sizeof(char)*(n*2+1));
        //strcpy(res[(*returnSize)-1], s);
        res[(*returnSize)-1] = strdup(s);
        return;
    }

    if (open < n) {
        s[open+close] = '(';
        dfs(open + 1, close, s, n, returnSize);
    }

    if (close < open) {
        s[open+close] = ')';
        dfs(open, close + 1, s, n, returnSize);
    }
}
char** generateParenthesis(int n, int* returnSize) {
    char s[n*2+1];
    //char* s = (char*)malloc(sizeof(char)*(n*2+1));
    *returnSize = 0;
    dfs(0, 0, s, n, returnSize);
    //free(s);
    return res;
}

// 1->1, 2->2, 3->5, 4->14, 5->42, 6->132, 7->429, 8->1430