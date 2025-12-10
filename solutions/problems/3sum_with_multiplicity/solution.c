#define MOD 1000000007

int compareInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumMulti(int* arr, int arrSize, int target) {
    qsort(arr, arrSize, sizeof(int), compareInt);
    long long result = 0;
    
    for (int i = 0; i < arrSize; i++) {
        // อย่าข้าม i เพราะเราต้องนับทุก triplet
        int newTarget = target - arr[i];
        int j = i + 1, k = arrSize - 1;
        
        while (j < k) {
            int sum = arr[j] + arr[k];
            
            if (sum < newTarget) {
                j++;
            } else if (sum > newTarget) {
                k--;
            } else {
                // arr[j] + arr[k] = newTarget
                if (arr[j] == arr[k]) {
                    // j ถึง k มีค่าเท่ากันทั้งหมด
                    int m = k - j + 1;
                    result += (long long)m * (m - 1) / 2;
                    result %= MOD;
                    break;  // ไม่มีคู่อื่นแล้ว
                } else {
                    int leftVal = arr[j], rightVal = arr[k];
                    int leftCount = 0, rightCount = 0;
                    
                    while (j <= k && arr[j] == leftVal) {
                        leftCount++;
                        j++;
                    }
                    
                    while (k >= j && arr[k] == rightVal) {
                        rightCount++;
                        k--;
                    }
                    
                    result += (long long)leftCount * rightCount;
                    result %= MOD;
                }
            }
        }
    }
    
    return (int)(result % MOD);
}