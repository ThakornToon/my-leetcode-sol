/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = 3;
    int* result = (int*)malloc(3 * sizeof(int));


    int* window = (int*)calloc(numsSize, sizeof(int));
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (i >= k) sum -= nums[i - k];
        if (i >= k - 1) window[i - k + 1] = sum;
    }
    
    // Left array: best index up to i
    int* left = (int*)malloc(numsSize * sizeof(int));
    int best = 0;
    for (int i = 0; i < numsSize; i++) {
        if (window[i] > window[best]) best = i;
        left[i] = best;
    }
    
    // Right array: best index from i to end
    int* right = (int*)malloc(numsSize * sizeof(int));
    best = numsSize - 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        if (window[i] >= window[best]) best = i;
        right[i] = best;
    }
    
    // Try all middle positions
    int maxSum = INT_MIN;
    for (int j = k; j < numsSize - k; j++) {
        int i = left[j - k];
        int l = right[j + k];
        int total = window[i] + window[j] + window[l];
        if (total > maxSum) {
            maxSum = total;
            result[0] = i;
            result[1] = j;
            result[2] = l;
        }
    }
    
    free(window);
    free(left);
    free(right);
    
    return result;
}