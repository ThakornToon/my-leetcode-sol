class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        
        // dp[i][j] = จำนวนวิธีใช้ลูกเต๋า i ลูกได้ผลรวม j
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;  // ไม่ใช้ลูกเต๋าได้ผลรวม 0 = 1 วิธี
        
        for (int dice = 1; dice <= n; dice++) {
            for (int sum = 1; sum <= target; sum++) {
                // ลูกเต๋าล่าสุดสามารถมีค่าได้ 1 ถึง k
                for (int face = 1; face <= k; face++) {
                    if (sum >= face) {
                        dp[dice][sum] = (dp[dice][sum] + dp[dice-1][sum-face]) % MOD;
                    }
                }
            }
        }
        
        return dp[n][target];
    }
};