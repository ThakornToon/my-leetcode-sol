#define MOD 1000000007

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int sumSubseqWidths(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    
    // สร้าง powers of 2 modulo MOD
    long long* pow2 = (long long*)malloc(numsSize * sizeof(long long));
    pow2[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }
    
    long long sum = 0;
    for (int i = 0; i < numsSize; i++) {
        // a[i] เป็น max ใน 2^i subsequence
        // a[i] เป็น min ใน 2^(n-1-i) subsequence
        long long maxCount = pow2[i];
        long long minCount = pow2[numsSize-1-i];
        
        sum = (sum + nums[i] * maxCount % MOD) % MOD; // กรณีที่เป็น max
        sum = (sum - nums[i] * minCount % MOD + MOD) % MOD; // กรณีที่เป็น min
    }
    
    free(pow2);
    return sum % MOD;
}