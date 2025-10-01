int findLengthOfLCIS(int* nums, int numsSize) {
    int max_length = 1;
    int current_length = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i-1]) {
            current_length++;
            if (current_length > max_length) {
                max_length = current_length;
            }
        } else {
            current_length = 1;
        }
    }
    
    return max_length;
}