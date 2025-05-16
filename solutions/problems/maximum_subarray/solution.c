int maxSubArray(int* nums, int numsSize) {
    int max = nums[0];
    int current_sum = 0;
    for(int n=0; n<numsSize; n++) {
        if(current_sum < 0) {
            current_sum = 0;
        }
        current_sum += nums[n];
        if(current_sum>max) {
            max = current_sum;
        }
    }
    return max;
}