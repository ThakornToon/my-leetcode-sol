class Solution {
    public int numberOfSubmatrices(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int count = 0;
        
        // prefix sums
        int[][] prefixX = new int[m + 1][n + 1];
        int[][] prefixY = new int[m + 1][n + 1];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int valX = (grid[i][j] == 'X') ? 1 : 0;
                int valY = (grid[i][j] == 'Y') ? 1 : 0;
                
                prefixX[i + 1][j + 1] = valX + prefixX[i][j + 1] + 
                                        prefixX[i + 1][j] - prefixX[i][j];
                prefixY[i + 1][j + 1] = valY + prefixY[i][j + 1] + 
                                        prefixY[i + 1][j] - prefixY[i][j];

                if (prefixX[i + 1][j + 1] > 0 && 
                    prefixX[i + 1][j + 1] == prefixY[i + 1][j + 1]) {
                    count++;
                }
            }
        }
    
        
        return count;
    }
}