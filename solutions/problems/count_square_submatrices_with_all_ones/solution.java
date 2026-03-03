class Solution {
    public int countSquares(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        
        // ใช้แค่ 2 arrays
        int[] prev = new int[cols];
        int[] curr = new int[cols];
        
        int total = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        curr[j] = 1;
                    } else {
                        curr[j] = Math.min(prev[j], 
                                   Math.min(curr[j-1], prev[j-1])) + 1;
                    }
                    total += curr[j];
                } else {
                    curr[j] = 0;
                }
            }
            
            // สลับ arrays
            int[] temp = prev;
            prev = curr;
            curr = temp;
        }
        
        return total;
    }
}