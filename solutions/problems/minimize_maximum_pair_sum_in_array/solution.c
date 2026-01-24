int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minPairSum(int* nums, int numsSize){
    // 1. เรียงลำดับอาร์เรย์
    qsort(nums, numsSize, sizeof(int), compare);
    
    // 2. ใช้ two pointers หาผลรวมคู่
    int left = 0;
    int right = numsSize - 1;
    int maxPairSum = 0;
    
    while (left < right) {
        int currentSum = nums[left] + nums[right];
        
        // อัปเดตค่าสูงสุด
        if (currentSum > maxPairSum) {
            maxPairSum = currentSum;
        }
        
        left++;
        right--;
    }
    
    return maxPairSum;
}