int dominantIndex(int* nums, int numsSize) {
    int maxIndex = 0;
    int maxVal = nums[0];
    int secondMax = -1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > maxVal) {
            secondMax = maxVal;
            maxVal = nums[i];
            maxIndex = i;
        } else if (nums[i] > secondMax) {
            secondMax = nums[i];
        }
    }
    
    // Handle case where all elements might be same
    if (secondMax == -1) {
        return 0; // Only one distinct element
    }
    
    return (maxVal >= 2 * secondMax) ? maxIndex : -1;
}