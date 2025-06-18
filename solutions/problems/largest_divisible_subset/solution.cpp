class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0);
        vector<int> from(nums.size(), -1);
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        from[i] = j;
                    }

                }
            }
            if (dp[maxi] < dp[i]) {
                maxi = i;
            }
        }

        vector<int> ans;
        while (maxi != -1) {
            ans.push_back(nums[maxi]);
            maxi = from[maxi];
        }
        return ans;
    }
};