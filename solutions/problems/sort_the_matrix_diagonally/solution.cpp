class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // เก็บค่าทั้งหมดในแต่ละ diagonal
        // key = i - j (ค่าคงที่สำหรับ diagonal เดียวกัน)
        map<int, vector<int>> diagonals;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diagonals[i - j].push_back(mat[i][j]);
            }
        }
        
        // เรียงแต่ละ diagonal
        for (auto& [key, vec] : diagonals) {
            sort(vec.begin(), vec.end(), greater<int>());  // เรียงจากมากไปน้อย
        }
        
        // ใส่ค่ากลับ
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = diagonals[i - j].back();
                diagonals[i - j].pop_back();
            }
        }
        
        return result;
    }
};