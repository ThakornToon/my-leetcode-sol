int pivotIndex(int* nums, int numsSize) {
    int totalSum = 0;
    
    // Calculate total sum
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }
    
    int leftSum = 0;
    
    for (int i = 0; i < numsSize; i++) {
        // rightSum = totalSum - leftSum - nums[i]
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }
    
    return -1;
}