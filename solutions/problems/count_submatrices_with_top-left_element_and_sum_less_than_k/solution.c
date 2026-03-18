int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];
    int count = 0;
    
    // สร้าง prefix sum array
    int** prefix = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        prefix[i] = (int*)calloc(n + 1, sizeof(int));
    }
    
    // คำนวณ prefix sum
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            prefix[i + 1][j + 1] = grid[i][j] + prefix[i][j + 1] + 
                                   prefix[i + 1][j] - prefix[i][j];
        }
    }
    
    // นับ submatrix ที่มีผลรวม ≤ k
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = prefix[i + 1][j + 1];
            if (sum <= k) {
                count++;
            } else {
                // ถ้าผลรวม > k แล้ว submatrix ที่ใหญ่กว่านี้ก็จะ > k ด้วย
                // แต่ต้องระวังเพราะอาจมี submatrix ในแถวอื่นที่ยัง ≤ k
                // ดังนั้นเราไม่สามารถ break ได้
            }
        }
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i <= m; i++) {
        free(prefix[i]);
    }
    free(prefix);
    
    return count;
}