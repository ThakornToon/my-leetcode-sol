int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minIncrementForUnique(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int moves = 0;
    int next = nums[0] + 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < next) {
            // คำนวณจำนวนที่ต้องเพิ่ม
            int increment = next - nums[i];
            nums[i] += increment;
            moves += increment;
        }
        next = nums[i] + 1;
    }
    
    return moves;
}