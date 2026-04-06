#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minDifficulty(int* jobDifficulty, int jobDifficultySize, int d) {
    int n = jobDifficultySize;
    
    // ถ้าจำนวนงานน้อยกว่าจำนวนวัน ไม่สามารถแบ่งได้
    if (n < d) {
        return -1;
    }
    
    // dp[i][j] = min difficulty สำหรับงาน i ตัวแรก แบ่งเป็น j วัน
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int*)malloc((d + 1) * sizeof(int));
        for (int j = 0; j <= d; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    
    // base case: 1 วัน ต้องทำงานทั้งหมด
    int maxSoFar = 0;
    for (int i = 1; i <= n; i++) {
        maxSoFar = (jobDifficulty[i-1] > maxSoFar) ? jobDifficulty[i-1] : maxSoFar;
        dp[i][1] = maxSoFar;
    }
    
    // คำนวณ DP
    for (int days = 2; days <= d; days++) {
        for (int i = days; i <= n; i++) {  // ต้องมีงานอย่างน้อย days ชิ้น
            int maxInLast = 0;
            // ลองให้วันสุดท้ายทำงานตั้งแต่ j+1 ถึง i
            for (int j = i - 1; j >= days - 1; j--) {
                maxInLast = (jobDifficulty[j] > maxInLast) ? jobDifficulty[j] : maxInLast;
                dp[i][days] = MIN(dp[i][days], dp[j][days - 1] + maxInLast);
            }
        }
    }
    
    int result = dp[n][d];
    
    // คืนหน่วยความจำ
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}