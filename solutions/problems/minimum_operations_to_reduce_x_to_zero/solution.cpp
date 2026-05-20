class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int num : nums) total += num;
        
        int target = total - x;
        if (target < 0) return -1;
        if (target == 0) return nums.size();
        
        unordered_map<int, int> prefixSum;
        prefixSum[0] = -1;
        
        int sum = 0;
        int maxLen = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (prefixSum.count(sum - target)) {
                maxLen = max(maxLen, i - prefixSum[sum - target]);
            }
            prefixSum[sum] = i;
        }
        
        return maxLen == -1 ? -1 : nums.size() - maxLen;
    }
};