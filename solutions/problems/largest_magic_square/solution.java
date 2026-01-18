class Solution {
    public int largestMagicSquare(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        // 1. สร้าง prefix sum สำหรับแถว
        int[][] rowPrefix = new int[m + 1][n + 1];
        // rowPrefix[i][j] = ผลรวมของแถว i (0-based) ตั้งแต่คอลัมน์ 0 ถึง j-1
        
        // 2. สร้าง prefix sum สำหรับคอลัมน์
        int[][] colPrefix = new int[m + 1][n + 1];
        // colPrefix[i][j] = ผลรวมของคอลัมน์ j (0-based) ตั้งแต่แถว 0 ถึง i-1
        
        // 3. คำนวณ prefix sums
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // หมายเหตุ: grid index เป็น 0-based แต่ prefix เป็น 1-based
                rowPrefix[i][j] = rowPrefix[i][j - 1] + grid[i - 1][j - 1];
                colPrefix[i][j] = colPrefix[i - 1][j] + grid[i - 1][j - 1];
            }
        }
        
        // 4. เริ่มจากขนาดใหญ่ที่สุดไปหาเล็ก
        int maxK = Math.min(m, n);
        
        for (int k = maxK; k >= 1; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    // ตรวจสอบสี่เหลี่ยมจัตุรัสที่เริ่มที่ (i,j) ขนาด k
                    
                    // 4.1 หาผลรวมแถวแรกเป็น reference
                    int firstRowSum = rowPrefix[i + 1][j + k] - rowPrefix[i + 1][j];
                    boolean valid = true;
                    
                    // 4.2 ตรวจสอบทุกแถว
                    for (int r = i + 1; r < i + k; r++) {
                        int rowSum = rowPrefix[r + 1][j + k] - rowPrefix[r + 1][j];
                        if (rowSum != firstRowSum) {
                            valid = false;
                            break;
                        }
                    }
                    
                    if (!valid) continue;
                    
                    // 4.3 ตรวจสอบทุกคอลัมน์
                    for (int c = j; c < j + k; c++) {
                        int colSum = colPrefix[i + k][c + 1] - colPrefix[i][c + 1];
                        if (colSum != firstRowSum) {
                            valid = false;
                            break;
                        }
                    }
                    
                    if (!valid) continue;
                    
                    // 4.4 ตรวจสอบเส้นทแยงมุมหลัก
                    int diagSum = 0;
                    for (int d = 0; d < k; d++) {
                        diagSum += grid[i + d][j + d];
                    }
                    if (diagSum != firstRowSum) continue;
                    
                    // 4.5 ตรวจสอบเส้นทแยงมุมรอง
                    int antiDiagSum = 0;
                    for (int d = 0; d < k; d++) {
                        antiDiagSum += grid[i + d][j + k - 1 - d];
                    }
                    if (antiDiagSum != firstRowSum) continue;
                    
                    // พบ magic square
                    return k;
                }
            }
        }
        
        // ไม่พบ magic square ที่ใหญ่กว่า 1x1
        return 1;
    }
}