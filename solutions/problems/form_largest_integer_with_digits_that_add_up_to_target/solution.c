#define MAX_TARGET 5001

char* largestNumber(int* cost, int costSize, int target) {
    // dp[t] = string ที่ดีที่สุดสำหรับ target t
    char** dp = (char**)malloc((target + 1) * sizeof(char*));
    for (int i = 0; i <= target; i++) {
        dp[i] = (char*)malloc(MAX_TARGET * sizeof(char));
        dp[i][0] = '\0';
    }
    
    // เติม dp
    for (int t = 1; t <= target; t++) {
        char* best = NULL;
        int bestLen = -1;
        
        for (int d = 1; d <= 9; d++) {
            int c = cost[d - 1];
            if (t >= c && (dp[t - c][0] != '\0' || t == c)) {
                // สร้างตัวเลขใหม่ = digit + dp[t-c]
                char temp[MAX_TARGET];
                sprintf(temp, "%d%s", d, dp[t - c]);
                
                int len = strlen(temp);
                if (bestLen < len || (bestLen == len && strcmp(temp, best) > 0)) {
                    bestLen = len;
                    if (best == NULL) {
                        best = (char*)malloc(MAX_TARGET * sizeof(char));
                    }
                    strcpy(best, temp);
                }
            }
        }
        
        if (best != NULL) {
            strcpy(dp[t], best);
            free(best);
        }
    }
    
    char* result = (char*)malloc((strlen(dp[target]) +21) * sizeof(char));
    if (dp[target][0] == '\0') {
        strcpy(result, "0");
    } else {
        strcpy(result, dp[target]);
    }
    
    for (int i = 0; i <= target; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;

}