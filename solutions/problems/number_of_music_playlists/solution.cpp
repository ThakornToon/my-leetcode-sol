class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int MOD = 1e9 + 7;
        // dp[i][j] = จำนวนวิธีสร้าง playlist ยาว i โดยใช้ j เพลงที่แตกต่างกัน
        // optimize space (ใช้เพียง 2 rows) curr, prev length
        vector<vector<long long>> dp(2, vector<long long>(n + 1, 0));
        dp[0][0] = 1;
        
        for (int i = 1; i <= goal; i++) {
            int curr = i % 2;
            int prev = 1 - curr;
            
            // รีเซ็ต row ปัจจุบัน
            fill(dp[curr].begin(), dp[curr].end(), 0);
            
            for (int j = 1; j <= min(i, n); j++) { // ลดการคิดที่ไม่จำเป็น
                // เลือกเพลงใหม่
                dp[curr][j] = (dp[curr][j] + dp[prev][j-1] * (n - (j-1))) % MOD;
                
                // เลือกเพลงเก่า
                if (j > k) {
                    dp[curr][j] = (dp[curr][j] + dp[prev][j] * (j - k)) % MOD;
                }
            }
        }
        
        return dp[goal % 2][n];
    }
};