int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    // สร้าง dp array ขนาด rows x cols
    int** dp = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        dp[i] = (int*)calloc(cols, sizeof(int));  // initialize เป็น 0
    }
    
    int total = 0;
    
    // คำนวณ dp
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    // แถวแรกหรือคอลัมน์แรก: square ได้แค่ขนาด 1
                    dp[i][j] = 1;
                } else {
                    // หาค่าน้อยที่สุดจาก 3 ทิศทาง แล้ว +1
                    int min = dp[i-1][j];
                    if (dp[i][j-1] < min) min = dp[i][j-1];
                    if (dp[i-1][j-1] < min) min = dp[i-1][j-1];
                    dp[i][j] = min + 1;
                }
                
                // บวกเข้ากับผลรวม
                total += dp[i][j];
            }
            // ถ้า matrix[i][j] == 0, dp[i][j] จะเป็น 0 อยู่แล้ว (จาก calloc)
        }
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i < rows; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return total;
}