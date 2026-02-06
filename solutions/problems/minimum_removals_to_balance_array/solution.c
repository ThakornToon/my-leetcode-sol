int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minRemoval(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int maxLength = 1;
    
    for (int i = 0; i < numsSize; i++) {
        // Binary search หาจุดสิ้นสุดที่ไกลที่สุดสำหรับ nums[i] เป็น min
        long long target = k * (long long)nums[i];
        
        int left = i, right = numsSize - 1;
        int best = i;  // อย่างน้อยก็ตัวมันเอง
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] <= target) {
                best = mid;  // ใช้ได้
                left = mid + 1;  // ลองหาที่ไกลกว่า
            } else {
                right = mid - 1;  // ใหญ่เกินไป
            }
        }
        
        int currentLength = best - i + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    
    return numsSize - maxLength;
}