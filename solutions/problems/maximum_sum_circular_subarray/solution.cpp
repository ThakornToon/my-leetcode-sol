class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int currentMax = 0;
        int currentMin = 0;
        
        for (int num : nums) {
            total += num;
            
            // Kadane's algorithm for max subarray
            currentMax = max(currentMax + num, num);
            maxSum = max(maxSum, currentMax);
            
            // Kadane's algorithm for min subarray
            currentMin = min(currentMin + num, num);
            minSum = min(minSum, currentMin);
        }
        
        // กรณี array มีแต่ค่าลบ circular จะเป็น 0
        if (maxSum < 0) {
            return maxSum;
        }
        
        // max ของ non-circular กับ circular
        return max(maxSum, total - minSum);
    }
};