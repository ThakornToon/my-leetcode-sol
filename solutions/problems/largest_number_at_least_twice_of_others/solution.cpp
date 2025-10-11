class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIndex = 0;
        int maxVal = nums[0];
        int secondMax = -1;
        
        // Find maximum and its index
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                secondMax = maxVal;
                maxVal = nums[i];
                maxIndex = i;
            } else if (nums[i] > secondMax) {
                secondMax = nums[i];
            }
        }
        
        // Check condition
        if (maxVal >= 2 * secondMax) {
            return maxIndex;
        }
        return -1;
    }
};