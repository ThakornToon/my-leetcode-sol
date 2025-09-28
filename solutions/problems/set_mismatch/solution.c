/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;
    
    // ใช้ array เดียวกันเป็น marker
    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0) {
            result[0] = abs(nums[i]);  // ตัวที่ซ้ำ
        } else {
            nums[index] = -nums[index];  // mark ว่าพบแล้ว
        }
    }
    
    // หาตัวที่หายไป
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            result[1] = i + 1;
            break;
        }
    }
    
    return result;
}