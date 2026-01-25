int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minimumDifference(int* nums, int numsSize, int k) {
    // กรณีพิเศษ
    if (k == 1 || numsSize <= 1) {
        return 0;
    }
    
    // 1. เรียงลำดับอาร์เรย์
    qsort(nums, numsSize, sizeof(int), compare);
    
    // 2. ใช้ sliding window หาความแตกต่างขั้นต่ำ
    int minDiff = INT_MAX;
    
    for (int i = 0; i <= numsSize - k; i++) {
        int diff = nums[i + k - 1] - nums[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    
    return minDiff;
}