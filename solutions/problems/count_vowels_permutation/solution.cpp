class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1e9 + 7;
        
        // dp[last_char] = จำนวนลำดับที่ลงท้ายด้วยตัวอักษรนั้น
        // 0:a, 1:e, 2:i, 3:o, 4:u
        vector<long long> dp(5, 1);  // สำหรับ n = 1
        vector<long long> new_dp(5, 0);
        
        // สำหรับแต่ละความยาว 2 ถึง n
        for (int len = 2; len <= n; len++) {
            // รีเซ็ต new_dp
            fill(new_dp.begin(), new_dp.end(), 0);
            
            // ตามกฎ:
            // a -> e
            new_dp[1] = (new_dp[1] + dp[0]) % MOD;
            
            // e -> a, i
            new_dp[0] = (new_dp[0] + dp[1]) % MOD;
            new_dp[2] = (new_dp[2] + dp[1]) % MOD;
            
            // i -> a, e, o, u
            new_dp[0] = (new_dp[0] + dp[2]) % MOD;
            new_dp[1] = (new_dp[1] + dp[2]) % MOD;
            new_dp[3] = (new_dp[3] + dp[2]) % MOD;
            new_dp[4] = (new_dp[4] + dp[2]) % MOD;
            
            // o -> i, u
            new_dp[2] = (new_dp[2] + dp[3]) % MOD;
            new_dp[4] = (new_dp[4] + dp[3]) % MOD;
            
            // u -> a
            new_dp[0] = (new_dp[0] + dp[4]) % MOD;
            
            // อัพเดท dp สำหรับความยาวถัดไป
            dp = new_dp;
        }
        
        // รวมคำตอบทั้งหมด
        long long result = 0;
        for (int i = 0; i < 5; i++) {
            result = (result + dp[i]) % MOD;
        }
        
        return result;
    }
};