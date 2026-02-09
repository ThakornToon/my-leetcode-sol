class Solution {
    public int oddCells(int m, int n, int[][] indices) {
        int[] rowCount = new int[m];
        int[] colCount = new int[n];
        
        // Count increments
        for (int[] idx : indices) {
            int ri = idx[0];
            int ci = idx[1];
            
            rowCount[ri]++;
            colCount[ci]++;
        }
        
        // Count odd rows
        int oddRows = 0;
        for (int count : rowCount) {
            if (count % 2 == 1) {
                oddRows++;
            }
        }
        int evenRows = m - oddRows;
        
        // Count odd columns
        int oddCols = 0;
        for (int count : colCount) {
            if (count % 2 == 1) {
                oddCols++;
            }
        }
        int evenCols = n - oddCols;
        
        // Apply formula
        return oddRows * evenCols + evenRows * oddCols;
    }
}