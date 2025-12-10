#define MOD 1000000007

int numMusicPlaylists(int n, int goal, int k) {
    // สร้างตาราง DP: dp[i][j] = จำนวนวิธีสร้าง playlist ยาว i โดยใช้ j เพลงที่แตกต่างกัน
    long long** dp = (long long**)malloc((goal + 1) * sizeof(long long*));
    for (int i = 0; i <= goal; i++) {
        dp[i] = (long long*)malloc((n + 1) * sizeof(long long));
        memset(dp[i], 0, (n + 1) * sizeof(long long));
    }
    
    // Base case: playlist ยาว 0 ใช้ 0 เพลง มี 1 วิธี (ว่าง)
    dp[0][0] = 1;
    
    for (int i = 1; i <= goal; i++) {  // ความยาว playlist
        for (int j = 1; j <= n; j++) {  // จำนวนเพลงที่แตกต่างกัน
            // กรณีที่: เลือกเพลงใหม่
            // มี (n - (j-1)) เพลงที่ยังไม่เคยใช้
            dp[i][j] = (dp[i][j] + dp[i-1][j-1] * (n - (j-1))) % MOD;
            
            // กรณีที่: เลือกเพลงเก่า
            // มีเพลงเก่าที่เลือกได้ = max(0, j - k) เพลง
            // เพราะเพลงที่เพิ่งเล่นไป k เพลงล่าสุดไม่สามารถเลือกได้ (ต้องคั่นอย่างน้อย k เพลง)
            dp[i][j] = (dp[i][j] + dp[i-1][j] * ((j - k > 0) ? (j - k) : 0)) % MOD;
        }
    }
    
    long long result = dp[goal][n];
    
    // คืน memory
    for (int i = 0; i <= goal; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return (int)result;
}