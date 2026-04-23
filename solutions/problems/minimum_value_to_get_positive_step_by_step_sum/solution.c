int minStartValue(int* nums, int numsSize) {
    int prefixSum = 0;
    int minPrefix = 0;
    
    for (int i = 0; i < numsSize; i++) {
        prefixSum += nums[i];
        if (prefixSum < minPrefix) {
            minPrefix = prefixSum;
        }
    }
    
    // ต้องการให้ prefixSum + startValue >= 1 เสมอ
    // ดังนั้น startValue >= 1 - minPrefix
    return 1 - minPrefix;
}