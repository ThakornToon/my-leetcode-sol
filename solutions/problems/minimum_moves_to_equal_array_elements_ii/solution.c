int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMoves2(int* nums, int numsSize) {
    // เรียงลำดับอาร์เรย์
    qsort(nums, numsSize, sizeof(int), compare);
    
    // หาค่ามัธยฐาน
    int median = nums[numsSize / 2];
    int moves = 0;
    
    // คำนวณผลรวมความแตกต่าง
    for (int i = 0; i < numsSize; i++) {
        moves += abs(nums[i] - median);
    }
    
    return moves;
}