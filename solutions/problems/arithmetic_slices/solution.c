int numberOfArithmeticSlices(int* nums, int numsSize) {
    if (numsSize < 3) return 0;
    
    int count = 0;
    int total = 0;
    
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
            count++;
            total += count;
        } else {
            count = 0;
        }
    }
    
    return total;
}