class Solution {

    private static final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public int closedIsland(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    boolean[] isClosed = {true};
                    dfs(grid, i, j, isClosed);
                    if (isClosed[0]) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }

    private void dfs(int[][] grid, int i, int j, boolean[] isClosed) {
        int m = grid.length;
        int n = grid[0].length;
        
        // ตรวจสอบขอบเขต
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 0) {
            return;
        }
        
        // ตรวจสอบว่าติดขอบหรือไม่
        if (i == 0 || i == m-1 || j == 0 || j == n-1) {
            isClosed[0] = false;
        }
        
        // mark visited (เปลี่ยนเป็น 2)
        grid[i][j] = 2;
        
        // สำรวจ 4 ทิศทาง
        for (int[] dir : DIRS) {
            dfs(grid, i + dir[0], j + dir[1], isClosed);
        }
    }
}