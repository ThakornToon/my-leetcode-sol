// ฟังก์ชันเปรียบเทียบสำหรับ qsort
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int specialArray(int* nums, int numsSize) {
    // เรียงลำดับ array
    qsort(nums, numsSize, sizeof(int), cmp);
    
    // ทดสอบ x = 0 ถึง n
    for (int x = 0; x <= numsSize; x++) {
        // หาจำนวนตัวเลขที่ >= x
        int count = 0;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] >= x) {
                count = numsSize - i; // เพราะ array เรียงแล้ว
                break;
            }
        }
        
        if (count == x) {
            return x;
        }
    }
    
    return -1;
}