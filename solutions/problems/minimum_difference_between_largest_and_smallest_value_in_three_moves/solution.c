
// ฟังก์ชันเปรียบเทียบสำหรับ qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minDifference(int* nums, int numsSize) {
    if (numsSize <= 4) {
        return 0;
    }
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    int minDiff = INT_MAX;
    
    // ลองลบ i ตัวจากซ้าย และลบ 3-i ตัวจากขวา
    for (int i = 0; i <= 3; i++) {
        int diff = nums[numsSize - 1 - (3 - i)] - nums[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    
    return minDiff;
}