int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b); // น้อยไปมาก
}

bool isPossibleDivide(int* nums, int numsSize, int k) {
    // ตรวจสอบจำนวน
    if (numsSize % k != 0) return false;
    
    // เรียงลำดับ
    qsort(nums, numsSize, sizeof(int), compare);
    
    // ใช้ array ในการติดตามว่าไพ่ถูกใช้ไปแล้วหรือยัง
    bool* used = (bool*)calloc(numsSize, sizeof(bool));
    
    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;  // ข้ามไพ่ที่ใช้ไปแล้ว
        
        int current = nums[i];
        int count = 1;
        used[i] = true;
        
        // หาไพ่ที่เรียงต่อจาก current
        for (int j = i + 1; j < numsSize && count < k; j++) {
            if (!used[j] && nums[j] == current + count) {
                used[j] = true;
                count++;
            }
        }
        
        // ถ้าหาไพ่ไม่ครบ groupSize
        if (count != k) {
            free(used);
            return false;
        }
    }
    
    free(used);
    return true;
}