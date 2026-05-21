#define MOD 1000000007

int waysToSplit(int* nums, int numsSize) {
    int n = numsSize;
    int* prefix = (int*)malloc((n + 1) * sizeof(int));
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    
    long long result = 0;
    int total = prefix[n];
    
    for (int i = 0; i < n - 2; i++) {
        int leftSum = prefix[i + 1];
        
        // Binary search หา j_min (ของ mid subarray)
        int leftBound = i + 2;
        int rightBound = n - 1;
        int j_min = n;
        
        // ตำแหน่งแรกที่ midSum >= leftSum
        while (leftBound <= rightBound) {
            int mid = leftBound + (rightBound - leftBound) / 2;
            // prefix[mid] - leftSum >= leftSum
            if (prefix[mid] >= 2 * leftSum) {
                j_min = mid;
                rightBound = mid - 1;
            } else {
                leftBound = mid + 1;
            }
        }
        
        // Binary search หา j_max (ของ mid subarray)
        leftBound = i + 2;
        rightBound = n - 1;
        int j_max = i + 1;
        
        // ตำแหน่งสุดท้ายที่ midSum <= rightSum
        while (leftBound <= rightBound) {
            int mid = leftBound + (rightBound - leftBound) / 2;
            // 2(leftSum + midSum) - leftSum <= total
            // midSum <= rightSum
            if (prefix[mid] <= (total + leftSum) / 2) {
                j_max = mid;
                leftBound = mid + 1;
            } else {
                rightBound = mid - 1;
            }
        }
        
        if (j_max >= j_min) {
            result = (result + (j_max - j_min + 1)) % MOD;
        }
    }
    
    free(prefix);
    return (int)result;
}