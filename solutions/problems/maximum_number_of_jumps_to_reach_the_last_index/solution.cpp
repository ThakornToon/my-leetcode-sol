class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // memo[i] = max jump i ไปถึง n - 1
        vector<int> memo(n, -2);  // -2 = unvisited(ยังไม่เคยคิด), -1 = impossible
        return dfs(nums, target, 0, memo);
    }

    int dfs(vector<int>& nums, int target, int pos, vector<int>& memo) {
        if (pos == nums.size() - 1) {
            return 0;
        }
        
        if (memo[pos] != -2) {
            return memo[pos];
        }
        
        int maxJumps = -1;
        
        for (int i = pos + 1; i < nums.size(); i++) {
            if (abs(nums[i] - nums[pos]) <= target) {
                int jumps = dfs(nums, target, i, memo);
                if (jumps != -1) {
                    maxJumps = max(maxJumps, 1 + jumps);
                }
            }
        }
        
        memo[pos] = maxJumps;
        return maxJumps;
    }
};