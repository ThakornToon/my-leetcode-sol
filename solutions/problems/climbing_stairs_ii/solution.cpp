class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // costs เป็น 1-indexed คือค่าใช้จ่ายของขั้น j อยู่ที่ costs[j-1]

        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;  // เริ่มที่ขั้น 0 ไม่มีค่าใช้จ่าย

        // i -> j
        for (int j = 1; j <= n; ++j) {
            for (int i = max(0, j - 3); i < j; ++i) {
                long long cost = dp[i] + (long long)(j - i) * (j - i);
                dp[j] = min(dp[j], cost + costs[j - 1]);
            }
        }
        return (int)dp[n];
    }
};