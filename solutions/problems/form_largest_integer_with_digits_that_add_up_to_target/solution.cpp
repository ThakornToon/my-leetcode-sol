class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target + 1, -1);  // ความยาวสูงสุด
        dp[0] = 0;
        
        for (int t = 1; t <= target; t++) {
            for (int d = 1; d <= 9; d++) {
                int c = cost[d - 1];
                if (t >= c && dp[t - c] != -1) {
                    dp[t] = max(dp[t], dp[t - c] + 1);
                }
            }
        }
        
        if (dp[target] == -1) return "0";
        
        string result;
        int remaining = target;
        while (remaining > 0) {
            for (int d = 9; d >= 1; d--) {
                int c = cost[d - 1];
                if (remaining >= c && dp[remaining] == dp[remaining - c] + 1) {
                    result += to_string(d);
                    remaining -= c;
                    break;
                }
            }
        }
        
        return result;
    }
};