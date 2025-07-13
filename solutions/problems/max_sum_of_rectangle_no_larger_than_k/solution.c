int maxSumSubmatrix(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    // สร้าง prefix sum array
    int** prefix = (int**)malloc((rows + 1) * sizeof(int*));
    for (int i = 0; i <= rows; i++) {
        prefix[i] = (int*)calloc(cols + 1, sizeof(int));
    }
    
    // คำนวณ prefix sum
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    
    int res = INT_MIN;
    
    // หาผลรวมของทุกสี่เหลี่ยมย่อย
    for (int r1 = 1; r1 <= rows; r1++) {
        for (int c1 = 1; c1 <= cols; c1++) {
            for (int r2 = r1; r2 <= rows; r2++) {
                for (int c2 = c1; c2 <= cols; c2++) {
                    int sum = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];
                    if (sum <= k && sum > res) {
                        res = sum;
                        if (res == k) {
                            // คืนค่าหน่วยความจำก่อน return
                            for (int i = 0; i <= rows; i++) {
                                free(prefix[i]);
                            }
                            free(prefix);
                            return k;
                        }
                    }
                }
            }
        }
    }
    
    // คืนค่าหน่วยความจำ
    for (int i = 0; i <= rows; i++) {
        free(prefix[i]);
    }
    free(prefix);
    
    return res;
}