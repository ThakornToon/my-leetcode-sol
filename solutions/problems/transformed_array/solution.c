/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructTransformedArray(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        
        if (val == 0) {
            result[i] = 0;
        } else if (val > 0) {
            // เลื่อนขวา
            int newIndex = (i + val) % numsSize;
            result[i] = nums[newIndex];
        } else {
            // เลื่อนซ้าย
            int steps = abs(val);
            steps = steps % numsSize;  // ลด steps ให้อยู่ใน range
            int newIndex = (i - steps + numsSize) % numsSize;
            result[i] = nums[newIndex];
        }
    }
    
    return result;

}