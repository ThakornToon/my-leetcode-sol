/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int compare(const void* a, const void *b) {
    return (*(int*)a - *(int*)b);
 }

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int** vv = NULL;
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    if (numsSize<4){
        return vv;
    }
    
    for (int i=0; i<numsSize-3; i++){
        if (i>0 && nums[i]==nums[i-1]){
            continue;
        }
        if (target / 4 < nums[i]) {
            break;
        }
        for (int j=i+1; j<numsSize-2; j++){
            if (j>i+1 && nums[j]==nums[j-1]){
                continue;
            }
            int l = j+1;
            int r = numsSize-1;
            while (l<r){
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];
                if (sum>INT_MAX){
                    r-=1;
                }
                else if (sum<INT_MIN){
                    l+=1;
                }
                else{
                    if (sum<target){
                        l+=1;
                    }
                    else if (sum>target){
                        r-=1;
                    }
                    else{
                        (*returnSize)++;
                        vv =(int**)realloc(vv, (*returnSize) * sizeof(int*));
                        vv[*returnSize - 1] = (int*)malloc(4 * sizeof(int*));
                        vv[*returnSize - 1][0] = nums[i];
                        vv[*returnSize - 1][1] = nums[j];
                        vv[*returnSize - 1][2] = nums[l];
                        vv[*returnSize - 1][3] = nums[r];
                        l+=1;
                        while (nums[l]==nums[l-1] && l<r){
                            l+=1;
                        }
                    }
                }
            }
        }
    }
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for(int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 4;
    }
    return vv;
}