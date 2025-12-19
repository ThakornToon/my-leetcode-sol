class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        
        // dp[i] = map<difference, length>
        vector<unordered_map<int, int>> dp(n);
        int max_len = 2;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                
                // Check if there's a sequence ending at j with this diff
                if (dp[j].count(diff)) {
                    dp[i][diff] = dp[j][diff] + 1;
                } else {
                    dp[i][diff] = 2;  // Start new sequence
                }
                
                max_len = max(max_len, dp[i][diff]);
            }
        }
        
        return max_len;
    }
};