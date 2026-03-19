class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        // prefix sums
        vector<vector<int>> prefixX(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> prefixY(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int valX = (grid[i][j] == 'X') ? 1 : 0;
                int valY = (grid[i][j] == 'Y') ? 1 : 0;
                
                prefixX[i + 1][j + 1] = valX + prefixX[i][j + 1] + prefixX[i + 1][j] - prefixX[i][j];
                prefixY[i + 1][j + 1] = valY + prefixY[i][j + 1] + prefixY[i + 1][j] - prefixY[i][j];
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (prefixX[i + 1][j + 1] > 0 && 
                    prefixX[i + 1][j + 1] == prefixY[i + 1][j + 1]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};