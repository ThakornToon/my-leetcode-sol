double findMaxAverage(int* nums, int numsSize, int k) {
    // คำนวณผลรวมของ window แรก
    int current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += nums[i];
    }
    
    int max_sum = current_sum;
    
    // เลื่อน window
    for (int i = k; i < numsSize; i++) {
        current_sum = current_sum - nums[i - k] + nums[i];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    
    return (double)max_sum / k;
}