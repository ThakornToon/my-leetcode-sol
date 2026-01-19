class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        
        // สร้าง prefix sum arrays
        vector<vector<int>> rowPrefix(m + 1, vector<int>(n + 1, 0));
        
        // คำนวณ prefix sums
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                rowPrefix[i][j] = rowPrefix[i][j-1] + mat[i-1][j-1];
            }
        }
        
        // ฟังก์ชันช่วยคำนวณผลรวมแถว
        auto getRowSum = [&](int r, int c1, int c2) {
            return rowPrefix[r+1][c2+1] - rowPrefix[r+1][c1];
        };
        
        int side = 1;

        // ตรวจสอบสี่เหลี่ยมที่เริ่มที่ (i,j) ขนาด 1
        for (int i = 0; i + side <= m; i++) {
            for (int j = 0; j + side <= n; j++) {
                int sum = 0;

                for (int r = i; r < i + side; r++) {
                    sum += getRowSum(r, j, j + side - 1);
                    if (sum > threshold) {
                        break;
                    }
                }

                if (sum <= threshold) {
                    side++;
                    j--;
                }
            }
        }
        return side - 1;
    }
};