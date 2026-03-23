class Solution {
    private static final int MOD = 1_000_000_007;
    public int maxProductPath(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        long[][] dpMax = new long[m][n];
        long[][] dpMin = new long[m][n];
        
        dpMax[0][0] = dpMin[0][0] = grid[0][0];
        
        // เติมแถวแรก
        for (int j = 1; j < n; j++) {
            dpMax[0][j] = dpMax[0][j-1] * grid[0][j];
            dpMin[0][j] = dpMin[0][j-1] * grid[0][j];
        }
        
        // เติมคอลัมน์แรก
        for (int i = 1; i < m; i++) {
            dpMax[i][0] = dpMax[i-1][0] * grid[i][0];
            dpMin[i][0] = dpMin[i-1][0] * grid[i][0];
        }
        
        // DP
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int val = grid[i][j];
                
                long fromTopMax = dpMax[i-1][j] * val;
                long fromTopMin = dpMin[i-1][j] * val;
                long fromLeftMax = dpMax[i][j-1] * val;
                long fromLeftMin = dpMin[i][j-1] * val;
                
                dpMax[i][j] = Math.max(
                    Math.max(fromTopMax, fromTopMin),
                    Math.max(fromLeftMax, fromLeftMin)
                );
                
                dpMin[i][j] = Math.min(
                    Math.min(fromTopMax, fromTopMin),
                    Math.min(fromLeftMax, fromLeftMin)
                );
            }
        }
        
        long result = dpMax[m-1][n-1];
        return (result < 0) ? -1 : (int)(result % MOD);
    }
}