bool divisorGame(int n) {
    // dp[i] = true ถ้าผู้เล่นปัจจุบันชนะเมื่อเริ่มที่ n = i
    bool* dp = (bool*)malloc((n + 2) * sizeof(bool));
    
    // Base cases
    dp[1] = false;  // n = 1 → แพ้ทันที
    dp[2] = true;   // n = 2 → ชนะ
    
    // คำนวณ dp[3..n]
    for (int i = 3; i <= n; i++) {
        dp[i] = false;
        
        // ตรวจสอบทุกตัวหารที่เป็นไปได้
        for (int x = 1; x * x <= i; x++) {
            if (i % x == 0) {
                // x เป็นตัวหาร
                if (x < i && !dp[i - x]) {
                    dp[i] = true;
                    break;
                }
                
                // i/x ก็เป็นตัวหาร
                int y = i / x;
                if (y < i && y != x && !dp[i - y]) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    
    bool result = dp[n];
    free(dp);
    return result;
}