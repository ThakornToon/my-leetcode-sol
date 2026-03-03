class Solution {
    public int minFallingPathSum(int[][] grid) {
        int n = grid.length;
        
        // กรณีพิเศษ: n == 1
        if (n == 1) {
            int min = grid[0][0];
            for (int j = 1; j < n; j++) {
                min = Math.min(min, grid[0][j]);
            }
            return min;
        }
        
        int[] prev = new int[n];
        int[] curr = new int[n];
        
        // initialize first row
        for (int j = 0; j < n; j++) {
            prev[j] = grid[0][j];
        }
        
        for (int i = 1; i < n; i++) {
            // หา smallest และ second smallest จาก prev
            int min1 = Integer.MAX_VALUE;
            int min2 = Integer.MAX_VALUE;
            int idx1 = -1;
            
            for (int j = 0; j < n; j++) {
                if (prev[j] < min1) {
                    min2 = min1;
                    min1 = prev[j];
                    idx1 = j;
                } else if (prev[j] < min2) {
                    min2 = prev[j];
                }
            }
            
            // คำนวณ curr
            for (int j = 0; j < n; j++) {
                if (j != idx1) {
                    curr[j] = grid[i][j] + min1;
                } else {
                    curr[j] = grid[i][j] + min2;
                }
            }
            
            // swap prev และ curr
            int[] temp = prev;
            prev = curr;
            curr = temp;
        }
        
        // หาค่าน้อยที่สุดในแถวสุดท้าย
        int result = prev[0];
        for (int j = 1; j < n; j++) {
            result = Math.min(result, prev[j]);
        }
        
        return result;
    }
}