#define min(a, b) ((a) < (b) ? (a) : (b))


int largestMagicSquare(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    // สร้าง prefix sum สำหรับแถว
    int** rowPrefix = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        rowPrefix[i] = (int*)calloc(n + 1, sizeof(int));
    }
    
    // สร้าง prefix sum สำหรับคอลัมน์
    int** colPrefix = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        colPrefix[i] = (int*)calloc(n + 1, sizeof(int));
    }
    
    // คำนวณ prefix sums
    for (int i = 1; i <= m; i++) {  // row - 1
        for (int j = 1; j <= n; j++) {  // col - 1
            rowPrefix[i][j] = rowPrefix[i][j-1] + grid[i-1][j-1];
            colPrefix[i][j] = colPrefix[i-1][j] + grid[i-1][j-1];
        }
    }
    
    // เริ่มจากขนาดใหญ่ที่สุดไปหาเล็ก
    int maxK = min(m, n);
    
    for (int k = maxK; k >= 1; k--) {
        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                // ตรวจสอบสี่เหลี่ยมจัตุรัสที่เริ่มที่ (i,j) ขนาด k
                
                // หาผลรวมแถวแรกเป็น reference
                int firstRowSum = rowPrefix[i+1][j+k] - rowPrefix[i+1][j];
                bool valid = true;
                
                // ตรวจสอบทุกแถว
                for (int r = i + 1; r < i + k; r++) {
                    int rowSum = rowPrefix[r+1][j+k] - rowPrefix[r+1][j];
                    if (rowSum != firstRowSum) {
                        valid = false;
                        break;
                    }
                }
                
                if (!valid) continue;
                
                // ตรวจสอบทุกคอลัมน์
                for (int c = j; c < j + k; c++) {
                    int colSum = colPrefix[i+k][c+1] - colPrefix[i][c+1];
                    if (colSum != firstRowSum) {
                        valid = false;
                        break;
                    }
                }
                
                if (!valid) continue;
                
                // ตรวจสอบเส้นทแยงมุมหลัก
                int diagSum = 0;
                for (int d = 0; d < k; d++) {
                    diagSum += grid[i+d][j+d];
                }
                if (diagSum != firstRowSum) continue;
                
                // ตรวจสอบเส้นทแยงมุมรอง
                int antiDiagSum = 0;
                for (int d = 0; d < k; d++) {
                    antiDiagSum += grid[i+d][j+k-1-d];
                }
                if (antiDiagSum != firstRowSum) continue;
                
                // พบ magic square
                // free memory
                for (int i = 0; i <= m; i++) {
                    free(rowPrefix[i]);
                    free(colPrefix[i]);
                }
                free(rowPrefix);
                free(colPrefix);
                
                return k;
            }
        }
    }
    
    // free memory
    for (int i = 0; i <= m; i++) {
        free(rowPrefix[i]);
        free(colPrefix[i]);
    }
    free(rowPrefix);
    free(colPrefix);
    
    return 1;  // มีอย่างน้อยขนาด 1x1 เสมอ
}