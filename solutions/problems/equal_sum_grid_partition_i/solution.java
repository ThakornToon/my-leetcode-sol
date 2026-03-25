class Solution {
    public boolean canPartitionGrid(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        long[][] prefix = new long[m + 1][n + 1];
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + 
                               prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        long total = prefix[m][n];
        if (total % 2 != 0) return false;
        long target = total / 2;
        
        // ตรวจสอบแนวตั้ง
        for (int j = 1; j < n; j++) {
            if (prefix[m][j] == target) return true;
        }
        
        // ตรวจสอบแนวนอน
        for (int i = 1; i < m; i++) {
            if (prefix[i][n] == target) return true;
        }
        
        return false;
    }
}