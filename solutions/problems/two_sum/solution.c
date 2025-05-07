/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int  i = 0; i < numsSize; i++) {
        for(int j=i+1; j<numsSize; j++){
            int k = nums[i];
            int h = nums[j];
            int m = k+h;
            if (m == target) {
                int* result = (int*)malloc(2 * sizeof(int));
                *returnSize = 2;
                result[0]=i;
                result[1]=j;
                return result;
            } 
        }
           
    }
    return NULL;
}