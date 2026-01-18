class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // สร้าง prefix sum arrays
        vector<vector<int>> rowPrefix(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> colPrefix(m + 1, vector<int>(n + 1, 0));
        
        // คำนวณ prefix sums
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                rowPrefix[i][j] = rowPrefix[i][j-1] + grid[i-1][j-1];
                colPrefix[i][j] = colPrefix[i-1][j] + grid[i-1][j-1];
            }
        }
        
        // ฟังก์ชันช่วยคำนวณผลรวมแถว
        auto getRowSum = [&](int r, int c1, int c2) {
            return rowPrefix[r+1][c2+1] - rowPrefix[r+1][c1];
        };
        
        // ฟังก์ชันช่วยคำนวณผลรวมคอลัมน์
        auto getColSum = [&](int c, int r1, int r2) {
            return colPrefix[r2+1][c+1] - colPrefix[r1][c+1];
        };
        
        // ไล่หาจากใหญ่ไปเล็ก
        for (int k = min(m, n); k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    // ตรวจสอบสี่เหลี่ยมที่เริ่มที่ (i,j) ขนาด k
                    
                    // หาผลรวมแถวแรกเป็น reference
                    int target = getRowSum(i, j, j + k - 1);
                    bool valid = true;
                    
                    // ตรวจสอบแถวอื่นๆ
                    for (int r = i + 1; r < i + k; r++) {
                        if (getRowSum(r, j, j + k - 1) != target) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;
                    
                    // ตรวจสอบคอลัมน์
                    for (int c = j; c < j + k; c++) {
                        if (getColSum(c, i, i + k - 1) != target) {
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
                    if (diagSum != target) continue;
                    
                    // ตรวจสอบเส้นทแยงมุมรอง
                    int antiDiagSum = 0;
                    for (int d = 0; d < k; d++) {
                        antiDiagSum += grid[i+d][j+k-1-d];
                    }
                    if (antiDiagSum != target) continue;
                    
                    // พบ magic square
                    return k;
                }
            }
        }
        
        // ไม่พบ magic square ที่ใหญ่กว่า 1x1
        return 1;
    }
};