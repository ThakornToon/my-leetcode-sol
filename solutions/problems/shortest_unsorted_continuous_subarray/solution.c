int findUnsortedSubarray(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;
    
    int max_val = INT_MIN;
    int min_val = INT_MAX;
    
    // หาค่า min ในส่วนที่ยังไม่เรียง (จากขวาไปซ้าย)
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i-1]) {
            min_val = (nums[i] < min_val) ? nums[i] : min_val;
        }
    }
    
    // หาค่า max ในส่วนที่ยังไม่เรียง (จากซ้ายไปขวา)
    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i] > nums[i+1]) {
            max_val = (nums[i] > max_val) ? nums[i] : max_val;
        }
    }
    
    // หาตำแหน่งเริ่มต้นที่ถูกต้องสำหรับ min
    int left;
    for (left = 0; left < numsSize; left++) {
        if (min_val < nums[left])
            break;
    }
    
    // หาตำแหน่งสิ้นสุดที่ถูกต้องสำหรับ max
    int right;
    for (right = numsSize - 1; right >= 0; right--) {
        if (max_val > nums[right])
            break;
    }
    
    return (right - left < 0) ? 0 : right - left + 1;
}