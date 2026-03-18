class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int maxArea = 0;
        
        // คำนวณความสูงสะสม
        for (int i = 0; i < m; i++) {
            // อัปเดตความสูงจากแถวก่อนหน้า
            for (int j = 0; j < n; j++) {
                if (i > 0 && matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
            
            // เรียงลำดับความสูงในแถวนี้
            Integer[] heights = new Integer[n];
            for (int j = 0; j < n; j++) {
                heights[j] = matrix[i][j];
            }
            Arrays.sort(heights, Collections.reverseOrder());
            
            // คำนวณพื้นที่
            for (int j = 0; j < n; j++) {
                if (heights[j] == 0) break;
                maxArea = Math.max(maxArea, heights[j] * (j + 1));
            }
        }
        
        return maxArea;
    }
}