#define MOD 1000000007

int countVowelPermutation(int n) {
    // dp สำหรับความยาวปัจจุบัน
    long long dp[5] = {1, 1, 1, 1, 1};  // n = 1
    
    // สำหรับความยาว 2 ถึง n
    for (int len = 2; len <= n; len++) {
        long long new_dp[5] = {0, 0, 0, 0, 0};
        
        // a -> e
        new_dp[1] = (new_dp[1] + dp[0]) % MOD;
        
        // e -> a, i
        new_dp[0] = (new_dp[0] + dp[1]) % MOD;
        new_dp[2] = (new_dp[2] + dp[1]) % MOD;
        
        // i -> a, e, o, u (ทุกตัวยกเว้น i)
        new_dp[0] = (new_dp[0] + dp[2]) % MOD;
        new_dp[1] = (new_dp[1] + dp[2]) % MOD;
        new_dp[3] = (new_dp[3] + dp[2]) % MOD;
        new_dp[4] = (new_dp[4] + dp[2]) % MOD;
        
        // o -> i, u
        new_dp[2] = (new_dp[2] + dp[3]) % MOD;
        new_dp[4] = (new_dp[4] + dp[3]) % MOD;
        
        // u -> a
        new_dp[0] = (new_dp[0] + dp[4]) % MOD;
        
        // คัดลอก new_dp ไปยัง dp
        for (int i = 0; i < 5; i++) {
            dp[i] = new_dp[i];
        }
    }
    
    // รวมผลลัพธ์
    long long result = 0;
    for (int i = 0; i < 5; i++) {
        result = (result + dp[i]) % MOD;
    }
    
    return (int)result;
}