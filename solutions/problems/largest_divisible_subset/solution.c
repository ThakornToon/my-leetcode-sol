/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int *dp = (int*)malloc(numsSize * sizeof(int));
    int *from = (int*)malloc(numsSize * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        from[i] = -1;
    }
    
    int maxi = 0;
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] % nums[j] == 0) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    from[i] = j;
                }
            }
        }
        if (dp[maxi] < dp[i]) {
            maxi = i;
        }
    }
    
    *returnSize = dp[maxi];
    int *ans = (int*)malloc((*returnSize) * sizeof(int));
    
    int index = *returnSize - 1;
    while (maxi != -1) {
        ans[index--] = nums[maxi];
        maxi = from[maxi];
    }
    
    free(dp);
    free(from);
    
    return ans;
}