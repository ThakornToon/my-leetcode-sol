class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1;
        int count = 0;
        int prefixSum = 0;
        
        for (int num : nums) {
            prefixSum += num;
            count += prefixSums[prefixSum - k];
            prefixSums[prefixSum]++;
        }
        
        return count;
    }
};