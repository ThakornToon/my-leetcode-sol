int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    // 1. เรียงจากน้อยไปมาก (negative numbers อยู่ข้างหน้า)
    qsort(nums, numsSize, sizeof(int), compare);
    
    // 2. Negate negative numbers ก่อน
    for (int i = 0; i < numsSize && k > 0; i++) {
        if (nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
        }
    }
    
    // 3. หาก k เหลือและเป็นคี่, negate ค่าที่น้อยที่สุด
    if (k % 2 == 1) {
        // หาค่าน้อยที่สุด
        int minIndex = 0;
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
        }
        nums[minIndex] = -nums[minIndex];
    }
    
    // 4. คำนวณ sum
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    
    return sum;
}