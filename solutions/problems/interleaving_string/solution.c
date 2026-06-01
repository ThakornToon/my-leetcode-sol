bool isInterleave(char* s1, char* s2, char* s3) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    
    // ถ้าความยาวรวมไม่เท่ากัน เป็นไปไม่ได้
    if (len1 + len2 != len3) {
        return false;
    }
    
    // สร้าง DP table ขนาด (len1+1) x (len2+1)
    // dp[i][j] = true ถ้า s1[0..i-1] และ s2[0..j-1] สามารถสร้าง s3[0..i+j-1] ได้
    bool** dp = (bool**)malloc((len1 + 1) * sizeof(bool*));
    for (int i = 0; i <= len1; i++) {
        dp[i] = (bool*)malloc((len2 + 1) * sizeof(bool));
        memset(dp[i], 0, (len2 + 1) * sizeof(bool));
    }
    
    // Base case: ไม่ใช้ตัวอักษรจากทั้ง s1 และ s2
    dp[0][0] = true;
    
    // เติมค่าใน DP table
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 && j == 0) continue;
            
            int k = i + j - 1; // ตำแหน่งใน s3
            
            // ถ้าใช้ตัวอักษรจาก s1
            if (i > 0 && dp[i-1][j] && s1[i-1] == s3[k]) {
                dp[i][j] = true;
            }
            // ถ้าใช้ตัวอักษรจาก s2
            else if (j > 0 && dp[i][j-1] && s2[j-1] == s3[k]) {
                dp[i][j] = true;
            }
        }
    }
    
    bool result = dp[len1][len2];
    
    // ปล่อยหน่วยความจำ
    for (int i = 0; i <= len1; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}