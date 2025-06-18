int wiggleMaxLength(int* nums, int numsSize) {
    if (numsSize < 2) return numsSize;
    
    int prev_diff = nums[1] - nums[0];
    int count = (prev_diff != 0) ? 2 : 1;
    
    for (int i = 2; i < numsSize; i++) {
        int diff = nums[i] - nums[i-1];
        if ((diff > 0 && prev_diff <= 0) || (diff < 0 && prev_diff >= 0)) {
            count++;
            prev_diff = diff;
        }
    }
    
    return count;
}