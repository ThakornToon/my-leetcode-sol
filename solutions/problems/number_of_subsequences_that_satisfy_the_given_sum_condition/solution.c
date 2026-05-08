#define MOD 1000000007

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int numSubseq(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    // precompute powers of 2
    int* pow2 = (int*)malloc((numsSize + 1) * sizeof(int));
    pow2[0] = 1;
    for (int i = 1; i <= numsSize; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
    
    int left = 0, right = numsSize - 1;
    int result = 0;
    
    // two pointer 
    while (left <= right) {
        if (nums[left] + nums[right] <= target) {
            result = (result + pow2[right - left]) % MOD;
            left++;
        } else {
            right--;
        }
    }
    
    free(pow2);
    return result;
}