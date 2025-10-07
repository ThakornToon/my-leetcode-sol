class Solution {
public:
    void backtrack(vector<int>& nums, int target, int index, int currentSum, int& count) {
        if (index == nums.size()) {
            if (currentSum == target) {
                count++;
            }
            return;
        }
        
        // Positive branch
        backtrack(nums, target, index + 1, currentSum + nums[index], count);
        
        // Negative branch
        backtrack(nums, target, index + 1, currentSum - nums[index], count);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        backtrack(nums, target, 0, 0, count);
        return count;
    }
};