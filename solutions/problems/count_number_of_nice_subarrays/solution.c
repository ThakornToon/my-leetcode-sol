int numberOfSubarrays(int* nums, int numsSize, int k) {
    // count[prefix] = จำนวนครั้งที่ prefix sum นี้ปรากฏ
    int* count = (int*)calloc(numsSize + 1, sizeof(int));
    count[0] = 1;  // prefix sum = 0 เกิดขึ้น 1 ครั้ง (ก่อนเริ่ม)
    
    int prefix = 0;  // prefix sum ปัจจุบัน
    int result = 0;
    
    for (int j = 0; j < numsSize; j++) {
        // เพิ่ม 1 ถ้าเป็นเลขคี่
        prefix += nums[j] % 2;
        
        // ถ้า prefix - k ≥ 0, นับจำนวนครั้งที่ prefix - k ปรากฏ
        if (prefix >= k) {
            result += count[prefix - k];
        }
        
        count[prefix]++;
    }
    
    free(count);
    return result;
}