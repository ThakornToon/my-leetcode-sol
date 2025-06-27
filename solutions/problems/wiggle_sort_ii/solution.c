int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void wiggleSort(int* nums, int numsSize) {
    // เรียงลำดับอาร์เรย์
    qsort(nums, numsSize, sizeof(int), compare);
    
    // สร้างอาร์เรย์ชั่วคราว
    int* temp = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        temp[i] = nums[i];
    }
    
    // คำนวณตำแหน่งกลาง
    int half = (numsSize + 1) / 2;
    int small = half - 1;
    int large = numsSize - 1;
    
    // จัดเรียงใหม่แบบ wiggle
    for (int i = 0; i < numsSize; i++) {
        nums[i] = (i % 2 == 0) ? temp[small--] : temp[large--];
    }
    
    free(temp);
}