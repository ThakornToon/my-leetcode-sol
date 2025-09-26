class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderMap;
        remainderMap[0] = -1; // Handle case when prefix sum itself is multiple of k
        
        int prefixSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int remainder = prefixSum % k;
            
            // Handle negative remainders
            if (remainder < 0) {
                remainder += k;
            }
            
            if (remainderMap.find(remainder) != remainderMap.end()) {
                // Check if subarray length >= 2
                if (i - remainderMap[remainder] >= 2) {
                    return true;
                }
            } else {
                remainderMap[remainder] = i;
            }
        }
        
        return false;
    }
};