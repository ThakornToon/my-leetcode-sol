#define MAX(a, b) ((a) > (b) ? (a) : (b))

// ตรวจสอบว่าสามารถกระโดดจาก i ไป j ได้หรือไม่
int canJump(int* arr, int n, int i, int j, int d) {
    if (i == j) return 0;
    if (arr[j] >= arr[i]) return 0;
    
    int step = (i < j) ? 1 : -1;
    for (int k = i + step; k != j; k += step) {
        if (arr[k] >= arr[i]) return 0;
    }
    return 1;
}

// DFS + Memoization
int dfs(int* arr, int n, int i, int d, int* memo) {
    if (memo[i] != -1) return memo[i];
    
    int maxSteps = 1;  // นับตัวเอง
    
    // ลองกระโดดไปทางขวา
    for (int j = i + 1; j <= i + d && j < n; j++) {
        if (canJump(arr, n, i, j, d)) {
            maxSteps = MAX(maxSteps, 1 + dfs(arr, n, j, d, memo));
        } else {
            break;  // เพราะ arr[j] >= arr[i] จะหยุดที่ตัวแรกที่เจอ
        }
    }
    
    // ลองกระโดดไปทางซ้าย
    for (int j = i - 1; j >= i - d && j >= 0; j--) {
        if (canJump(arr, n, i, j, d)) {
            maxSteps = MAX(maxSteps, 1 + dfs(arr, n, j, d, memo));
        } else {
            break;
        }
    }
    
    memo[i] = maxSteps;
    return maxSteps;
}

int maxJumps(int* arr, int arrSize, int d) {
    int* memo = (int*)malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        memo[i] = -1;
    }
    
    int result = 0;

    // ลองเริ่มที่ i 
    for (int i = 0; i < arrSize; i++) {
        result = MAX(result, dfs(arr, arrSize, i, d, memo));
    }
    
    free(memo);
    return result;
}