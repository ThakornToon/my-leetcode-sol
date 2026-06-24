class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEndingHere = 0;
        int maxSoFar = INT_MIN;
        int minEndingHere = 0;
        int minSoFar = INT_MAX;
        
        for (int num : nums) {
            // Max subarray sum
            maxEndingHere = max(num, maxEndingHere + num);
            maxSoFar = max(maxSoFar, maxEndingHere);
            
            // Min subarray sum
            minEndingHere = min(num, minEndingHere + num);
            minSoFar = min(minSoFar, minEndingHere);
        }
        
        return max(maxSoFar, -minSoFar);
    }
};