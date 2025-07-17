class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        // dp[i][j][k] แทนจำนวนวิธีที่ถูกต้องสำหรับ i วันที่ผ่านมา โดยมีขาดเรียน j ครั้ง และมาสายติดต่อกัน k ครั้ง
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        // Base case: 0 วัน
        dp[0][0][0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    // เพิ่ม 'P' (Present)
                    dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][k]) % MOD;
                    
                    // เพิ่ม 'A' (Absent) ถ้ายังไม่เกิน 1 ครั้ง
                    if (j < 1) {
                        dp[i][j+1][0] = (dp[i][j+1][0] + dp[i-1][j][k]) % MOD;
                    }
                    
                    // เพิ่ม 'L' (Late) ถ้ายังไม่ต่อเนื่อง 2 ครั้ง
                    if (k < 2) {
                        dp[i][j][k+1] = (dp[i][j][k+1] + dp[i-1][j][k]) % MOD;
                    }
                }
            }
        }
        
        // รวมทุกกรณีที่เป็นไปได้หลังจาก n วัน
        int result = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                result = (result + dp[n][j][k]) % MOD;
            }
        }
        
        return result;
    }
};