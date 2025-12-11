int min(int a, int b) {
    return a > b ? b : a;
}

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    
    // ใช้แค่ 2 rows: prev (แถวก่อนหน้า) และ curr (แถวปัจจุบัน)
    int* prev = (int*)malloc(n * sizeof(int));
    int* curr = (int*)malloc(n * sizeof(int));
    
    // Initialize prev row
    for (int j = 0; j < n; j++) {
        prev[j] = matrix[0][j];
    }
    
    // Process each row
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // คำนวณจากแถวก่อนหน้า
            int left = (j > 0) ? prev[j-1] : INT_MAX;
            int middle = prev[j];
            int right = (j < n-1) ? prev[j+1] : INT_MAX;
            
            curr[j] = matrix[i][j] + min(left, min(middle, right));
        }
        
        // Swap rows
        int* temp = prev;
        prev = curr;
        curr = temp;
    }
    
    // หาค่าต่ำสุดในแถวสุดท้าย
    int result = INT_MAX;
    for (int j = 0; j < n; j++) {
        result = min(result, prev[j]);
    }
    
    free(prev);
    free(curr);
    
    return result;
}