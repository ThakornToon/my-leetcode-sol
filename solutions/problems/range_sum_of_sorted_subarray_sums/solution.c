#define MOD 1000000007

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int rangeSum(int* nums, int numsSize, int n, int left, int right) {
    int total = n * (n + 1) / 2;
    int* sums = (int*)malloc(total * sizeof(int));
    int idx = 0;
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            sums[idx++] = sum;
        }
    }
    
    qsort(sums, total, sizeof(int), compare);
    
    long long result = 0;
    for (int i = left - 1; i < right; i++) {
        result = (result + sums[i]) % MOD;
    }
    
    free(sums);
    return (int)result;
}