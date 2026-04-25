class Solution {
private:
    const int MOD = 1000000007;
    
public:
    int numberOfArrays(string s, int k) {
        int n = s.length();

        // ขวาไปซ้าย
        vector<long long> dp(n + 1, 0);
        dp[n] = 1;  // empty string
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            
            long long num = 0;

            // แบ่งส่วนปัจจุบัน i ถึง j ทุกความยาวที่เป็นไปได้
            for (int j = i; j < n; j++) {
                num = num * 10 + (s[j] - '0');
                if (num > k) break;
                dp[i] = (dp[i] + dp[j + 1]) % MOD;
            }
        }
        
        return dp[0];
    }
};