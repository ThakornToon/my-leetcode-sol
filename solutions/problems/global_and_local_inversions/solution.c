bool isIdealPermutation(int* nums, int numsSize) {
    int max_val = nums[0];
    
    for (int i = 2; i < numsSize; i++) {
        if (max_val > nums[i]) {
            return false;
        }
        max_val = (nums[i-1] > max_val) ? nums[i-1] : max_val;
    }
    
    return true;
}