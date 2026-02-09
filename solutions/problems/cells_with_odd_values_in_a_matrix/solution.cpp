class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row_count(m, 0);
        vector<int> col_count(n, 0);
        
        // Count increments
        for (auto& idx : indices) {
            int ri = idx[0];
            int ci = idx[1];
            
            row_count[ri]++;
            col_count[ci]++;
        }
        
        // Count odd rows
        int odd_rows = 0;
        for (int count : row_count) {
            if (count % 2 == 1) {
                odd_rows++;
            }
        }
        int even_rows = m - odd_rows;
        
        // Count odd columns
        int odd_cols = 0;
        for (int count : col_count) {
            if (count % 2 == 1) {
                odd_cols++;
            }
        }
        int even_cols = n - odd_cols;
        
        // สูตร: odd_cells = odd_rows * even_cols + even_rows * odd_cols
        return odd_rows * even_cols + even_rows * odd_cols;
    }
};