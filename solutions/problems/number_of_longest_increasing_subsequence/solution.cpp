class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();        
        vector<int> dp(n, 1);    // length of LIS ending at i
        vector<int> count(n, 1); // number of LIS ending at i
        int max_len = 1;
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
            
            if (dp[i] > max_len) {
                max_len = dp[i];
                result = count[i];
            } else if (dp[i] == max_len) {
                result += count[i];
            }
        }
        
        return result;
    }
};