int missingNumber(int* nums, int numsSize) {
    int res =  numsSize;

    for (int i = 0; i <  numsSize; i++) {
        res += i - nums[i];
    }
    // ผลรวม 0..=n - ตัวเลขทั้งหมด = ตัวเลขที่หายไป
    return res;
}