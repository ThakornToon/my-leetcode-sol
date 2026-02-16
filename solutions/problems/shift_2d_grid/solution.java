class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int total = m * n;
        
        // ลด k
        k = k % total;
        if (k == 0) {
            // สร้าง grid เดิม
            List<List<Integer>> result = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                List<Integer> row = new ArrayList<>();
                for (int j = 0; j < n; j++) {
                    row.add(grid[i][j]);
                }
                result.add(row);
            }
            return result;
        }
        
        // สร้าง grid ผลลัพธ์
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                row.add(0);
            }
            result.add(row);
        }
        
        // ใส่ค่าในตำแหน่งใหม่
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // คำนวณตำแหน่งใหม่
                int oldIndex = i * n + j;
                int newIndex = (oldIndex + k) % total;
                int newRow = newIndex / n;
                int newCol = newIndex % n;
                
                result.get(newRow).set(newCol, grid[i][j]);
            }
        }
        
        return result;
    }
}