int repeatedNTimes(int* nums, int numsSize) {
    // ตรวจสอบทุกคู่ที่ติดกัน
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return nums[i];
        }
    }
    
    // ตรวจสอบทุกคู่ที่ห่าง 2 ตำแหน่ง
    for (int i = 0; i < numsSize - 2; i++) {
        if (nums[i] == nums[i + 2] || nums[i] == nums[i + 1]) {
            return nums[i];
        }
    }
    
    // ถ้าไม่เจอในตำแหน่งข้างเคียง (กรณี [x, a, b, x])
    return nums[0] == nums[3] ? nums[0] : nums[1];
}