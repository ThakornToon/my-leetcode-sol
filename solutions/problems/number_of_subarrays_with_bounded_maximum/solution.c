int numSubarrayBoundedMax(int* nums, int numsSize, int left, int right) {
    int count = 0;
    int last_in_range = -1;    // ดัชนีสุดท้ายที่เจอตัวเลขในช่วง [left, right]
    int last_gt_right = -1;    // ดัชนีสุดท้ายที่เจอตัวเลข > right
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > right) {
            last_gt_right = i;
            last_in_range = i; // reset เพราะตัวนี้เป็นตัวแบ่ง
        } else if (nums[i] >= left && nums[i] <= right) {
            last_in_range = i;
        }
        
        // จำนวน subarrays ที่ลงท้ายที่ i = last_in_range - last_gt_right
        if (last_in_range > last_gt_right) {
            count += (last_in_range - last_gt_right);
        }
    }
    
    return count;
}