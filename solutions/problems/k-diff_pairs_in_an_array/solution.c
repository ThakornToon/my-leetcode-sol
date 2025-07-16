int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findPairs(int* nums, int numsSize, int k) {
    if (numsSize < 2) return 0;
    
    // น้อยไปมาก
    qsort(nums, numsSize, sizeof(int), compare);
    
    int count = 0;
    int left = 0, right = 1;
    
    while (right < numsSize) {
        int diff = nums[right] - nums[left];
        
        if (diff < k) {
            right++;
        } else if (diff > k) {
            left++;
            if (left == right) right++;
        } else {
            count++;
            left++;
            right++;
            // ข้ามตัวเลขที่ซ้ำกัน
            while (right < numsSize && nums[right] == nums[right - 1]) right++;
        }
    }
    
    return count;
}