int minDeletionSize(char** strs, int strsSize) {
    int n = strlen(strs[0]);  // จำนวน columns
    int m = strsSize;         // จำนวน rows
    
    // dp[i] = ความยาวมากที่สุดที่ลงท้ายที่ column i
    int* dp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    
    // หาความยาวที่ยาวสุด
    int maxLen = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // ตรวจสอบว่า column j มาก่อน column i ได้หรือไม่สำหรับทุกสตริง
            bool valid = true;
            for (int k = 0; k < m; k++) {
                if (strs[k][j] > strs[k][i]) {
                    valid = false;
                    break;
                }
            }
            
            // . . . j i
            if (valid && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                if (dp[i] > maxLen) {
                    maxLen = dp[i];
                }
            }
        }
    }
    
    free(dp);
    return n - maxLen;  // จำนวน columns ที่ต้องลบ
}