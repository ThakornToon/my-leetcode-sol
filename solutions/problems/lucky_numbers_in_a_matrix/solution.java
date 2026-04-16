class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        
        int[] rowMins = new int[m];
        int[] colMaxs = new int[n];
        
        Arrays.fill(rowMins, Integer.MAX_VALUE);
        Arrays.fill(colMaxs, Integer.MIN_VALUE);
        
        // วนลูปครั้งเดียว: หาทั้ง rowMin และ colMax พร้อมกัน
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j];
                rowMins[i] = Math.min(rowMins[i], val);
                colMaxs[j] = Math.max(colMaxs[j], val);
            }
        }
        
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == rowMins[i] && matrix[i][j] == colMaxs[j]) {
                    result.add(matrix[i][j]);
                }
            }
        }
        
        return result;
    }
}