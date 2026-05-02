bool kLengthApart(int* nums, int numsSize, int k) {
    int lastOne = -1;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            if (lastOne != -1 && i - lastOne - 1 < k) {
                return false;
            }
            lastOne = i;
        }
    }
    
    return true;
}