bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    // คำนวณผลรวมทั้งหมดของ matrix
    long long total = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            total += grid[i][j];
        }
    }
    
    // ถ้าผลรวมเป็นเลขคี่ ไม่สามารถแบ่งให้เท่ากันได้
    if (total % 2 != 0) {
        return false;
    }
    
    long long target = total / 2;
    
    
    // คำนวณ prefix sum สะสมทีละคอลัมน์
    long long* colPrefix = (long long*)calloc(n, sizeof(long long));
    for (int j = 0; j < n; j++) {
        long long colSum = 0;
        for (int i = 0; i < m; i++) {
            colSum += grid[i][j];
        }

        if (j == 0) {
            colPrefix[j] = colSum;
        } else {
            colPrefix[j] = colPrefix[j-1] + colSum;
        }
        
        // ตรวจสอบว่าตัดระหว่างคอลัมน์ j กับ j+1
        if (j < n - 1 && colPrefix[j] == target) {
            free(colPrefix);
            return true;
        }
    }
    free(colPrefix);
    
    // ตรวจสอบการตัดแนวนอน (ระหว่างแถว)
    long long* rowPrefix = (long long*)calloc(m, sizeof(long long));
    for (int i = 0; i < m; i++) {
        long long rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += grid[i][j];
        }

        if (i == 0) {
            rowPrefix[i] = rowSum;
        } else {
            rowPrefix[i] = rowPrefix[i-1] + rowSum;
        }
        
        // ตรวจสอบว่าตัดระหว่างแถว i กับ i+1
        if (i < m - 1 && rowPrefix[i] == target) {
            free(rowPrefix);
            return true;
        }
    }
    free(rowPrefix);
    
    return false;
}