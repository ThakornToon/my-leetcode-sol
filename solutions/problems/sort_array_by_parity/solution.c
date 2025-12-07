/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    // Copy original array
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i];
    }
    
    // Two pointers in-place
    int even_ptr = 0;
    for (int i = 0; i < numsSize; i++) {
        if (result[i] % 2 == 0) {
            // Swap
            int temp = result[i];
            result[i] = result[even_ptr];
            result[even_ptr] = temp;
            even_ptr++;
        }
    }
    
    return result;
}