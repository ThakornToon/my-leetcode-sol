int splitArray(int* nums, int numsSize, int k) {
    // หาค่าสูงสุดและผลรวมทั้งหมด
    int max_num = 0;
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max_num) max_num = nums[i];
        sum += nums[i];
    }
    
    int left = max_num;
    int right = sum;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = 1;
        int current_sum = 0;
        
        for (int i = 0; i < numsSize; i++) {
            if (current_sum + nums[i] > mid) {
                count++;
                current_sum = nums[i];
            } else {
                current_sum += nums[i];
            }
        }
        
        if (count > k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}