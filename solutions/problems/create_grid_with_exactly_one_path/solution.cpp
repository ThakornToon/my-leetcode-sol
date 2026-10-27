class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> g(m, string(n, '#'));
        
        // เปิดแถวแรกทั้งหมดเป็นช่องว่าง
        for (int j = 0; j < n; ++j) {
            g[0][j] = '.';
        }
        
        // เปิดคอลัมน์ขวาสุดทั้งหมดเป็นช่องว่าง
        for (int i = 0; i < m; ++i) {
            g[i][n - 1] = '.';
        }
        
        return g;
    }
};