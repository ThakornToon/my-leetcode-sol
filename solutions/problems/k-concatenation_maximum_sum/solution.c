#define MOD 1000000007

long long max(long long a, long long b) {
    return a > b ? a : b;
}

long long min(long long a, long long b) {
    return a < b ? a : b;
}

int kConcatenationMaxSum(int* arr, int arrSize, int k) {
    // 1. หาผลรวมทั้งหมด
    long long totalSum = 0;
    for (int i = 0; i < arrSize; i++) {
        totalSum += arr[i];
    }
    
    // 2. Kadane's algorithm สำหรับ 1 สำเนา
    long long maxEndingHere = 0;
    long long maxSoFar = 0;
    
    for (int i = 0; i < arrSize; i++) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    // 3. ถ้า k == 1
    if (k == 1) {
        return maxSoFar % MOD;
    }
    
    // 4. หา max prefix sum
    long long maxPrefix = 0;
    long long prefixSum = 0;
    for (int i = 0; i < arrSize; i++) {
        prefixSum += arr[i];
        maxPrefix = max(maxPrefix, prefixSum);
    }
    
    // 5. หา max suffix sum
    long long maxSuffix = 0;
    long long suffixSum = 0;
    for (int i = arrSize - 1; i >= 0; i--) {
        suffixSum += arr[i];
        maxSuffix = max(maxSuffix, suffixSum);
    }
    
    // 6. คำนวณผลลัพธ์
    long long result = 0;
    
    // กรณีภายใน 1 สำเนา
    result = max(result, maxSoFar);
    
    // กรณีคร่อม 2 สำเนา
    result = max(result, maxPrefix + maxSuffix);
    
    // กรณีใช้ k สำเนา (ถ้าผลรวมทั้งหมดเป็นบวก)
    if (totalSum > 0) {
        result = max(result, maxPrefix + maxSuffix + (k - 2) * totalSum);
    }
    
    return result % MOD;
}