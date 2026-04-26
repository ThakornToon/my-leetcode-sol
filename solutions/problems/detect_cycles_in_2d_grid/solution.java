class Solution {
    private int m, n;
    private int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    public boolean containsCycle(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (hasCycle(grid, i, j, visited)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    private boolean hasCycle(char[][] grid, int startX, int startY, boolean[][] visited) {
        int m = grid.length, n = grid[0].length;
        char target = grid[startX][startY];
        Deque<int[]> stack = new ArrayDeque<>();
        stack.push(new int[]{startX, startY, -1, -1});
        visited[startX][startY] = true;
        
        while (!stack.isEmpty()) {
            int[] curr = stack.pop();
            int x = curr[0], y = curr[1], px = curr[2], py = curr[3];
            
            for (int[] dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (grid[nx][ny] != target) continue;
                if (nx == px && ny == py) continue;
                
                if (visited[nx][ny]) return true;
                
                visited[nx][ny] = true;
                stack.push(new int[]{nx, ny, x, y});
            }
        }
        
        return false;
    }
}