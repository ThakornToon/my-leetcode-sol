int maxSubarraySumCircular(int* nums, int numsSize) {    
    int total = 0;
    int maxSum = INT_MIN;
    int minSum = INT_MAX;
    int currentMax = 0;
    int currentMin = 0;
    
    // Kadane's algorithm สำหรับทั้ง max subarray และ min subarray
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
        
        // สำหรับ max subarray
        currentMax = (currentMax > 0) ? currentMax + nums[i] : nums[i];
        maxSum = (currentMax > maxSum) ? currentMax : maxSum;
        
        // สำหรับ min subarray
        currentMin = (currentMin < 0) ? currentMin + nums[i] : nums[i];
        minSum = (currentMin < minSum) ? currentMin : minSum;
    }
    
    // กรณีที่ 1: max subarray ปกติ (ไม่ wrap around)
    // กรณีที่ 2: max subarray แบบ circular (wrap around) = total - minSum
    // กรณีทุกตัวเป็นค่าลบ circularSum จะ = 0 ซึ่งผิด
    if (maxSum < 0) {
        return maxSum;
    }
    
    int circularSum = total - minSum;
    return (maxSum > circularSum) ? maxSum : circularSum;
}