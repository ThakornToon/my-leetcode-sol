int smallestRangeI(int* nums, int numsSize, int k) {
    int min = nums[0], max = nums[0];
    
    // หาค่าสูงสุดและต่ำสุด
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
    }
    
    // คำนวณคำตอบ
    int result = (max - k) - (min + k);
    return result > 0 ? result : 0;
}