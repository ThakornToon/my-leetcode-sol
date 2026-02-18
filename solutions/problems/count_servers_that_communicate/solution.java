class Solution {
    public int countServers(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        int[] rowCount = new int[m];
        int[] colCount = new int[n];
        int total = 0;
        
        // นับเซิร์ฟเวอร์
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    total++;
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        // นับ isolated servers
        int isolated = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
                    isolated++;
                }
            }
        }
        
        return total - isolated;
    }
}