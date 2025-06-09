class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> rob(n, 0);
        vector<int> no_rob(n, 0);
        for (int i = 0; i < n; i++) {
            if (i >= 2) {
                rob[i] = max(rob[i-2], no_rob[i-1]) + nums[i];
                no_rob[i] = max(no_rob[i-1], rob[i-1]);
            }
            else {
                rob[i] = nums[i];
                no_rob[i] = rob[i] - nums[i];
                if (i != 0 && no_rob[i] < rob[i-1]) {
                    no_rob[i] = rob[i-1];
                }
            }
        }
        return max(rob[n-1], no_rob[n-1]);
    }
};