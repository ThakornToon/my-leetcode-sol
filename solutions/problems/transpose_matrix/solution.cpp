class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();      // จำนวนแถว
        int n = matrix[0].size();   // จำนวนคอลัมน์
        
        // สร้าง matrix ผลลัพธ์ขนาด n × m
        vector<vector<int>> result(n, vector<int>(m));
        
        // คำนวณ transpose
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][i] = matrix[i][j];
            }
        }
        
        return result;
    }
};