int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int smallestRangeII(int* nums, int numsSize, int k) {
    // เรียงลำดับ
    qsort(nums, numsSize, sizeof(int), compare);
    
    // ค่าเริ่มต้น (ทั้งหมด +k หรือทั้งหมด -k)
    int answer = nums[numsSize-1] - nums[0];
    
    for (int i = 0; i < numsSize - 1; i++) {
        // สูงสุดที่เป็นไปได้
        int high = nums[numsSize-1] - k;
        if (nums[i] + k > high) high = nums[i] + k;
        
        // ต่ำสุดที่เป็นไปได้
        int low = nums[0] + k;
        if (nums[i+1] - k < low) low = nums[i+1] - k;
        
        // คำนวณความต่าง
        int diff = high - low;
        if (diff < answer) answer = diff;
    }
    
    return answer;
}