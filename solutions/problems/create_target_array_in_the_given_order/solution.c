/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize) {
    *returnSize = numsSize;
    int* target = (int*)malloc(numsSize * sizeof(int));
    
    // เริ่มต้น target ว่าง
    int size = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int pos = index[i];
        int val = nums[i];
        
        // shift elements to the right
        for (int j = size; j > pos; j--) {
            target[j] = target[j - 1];
        }
        
        target[pos] = val;
        size++;
    }
    
    return target;
}