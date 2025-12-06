class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int xy = 0, xz = 0, yz = 0;
        
        // สำหรับเก็บค่าสูงสุดของแต่ละ column
        vector<int> colMax(n, 0);
        
        for (int i = 0; i < n; i++) {
            int rowMax = 0;  // ค่าสูงสุดใน row นี้
            
            for (int j = 0; j < n; j++) {
                // XY-plane: นับถ้ามีกล่อง
                if (grid[i][j] > 0) {
                    xy++;
                }
                
                // หาค่าสูงสุดใน row
                rowMax = max(rowMax, grid[i][j]);
                
                // หาค่าสูงสุดใน column
                colMax[j] = max(colMax[j], grid[i][j]);
            }
            
            // บวกค่าสูงสุดของ row นี้
            yz += rowMax;
        }
        
        // บวกค่าสูงสุดของทุก column
        for (int j = 0; j < n; j++) {
            xz += colMax[j];
        }
        
        return xy + xz + yz;
    }
};