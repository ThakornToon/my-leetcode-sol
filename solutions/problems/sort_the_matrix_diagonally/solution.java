class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        
        int[][] result = new int[m][n];
        for (int i = 0; i < m; i++) {
            result[i] = mat[i].clone();
        }
        
        for (int k = 0; k < m + n - 1; k++) {
            int startI = Math.max(0, k - n + 1);
            int startJ = Math.max(0, n - 1 - k);
            
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            int i = startI, j = startJ;
            while (i < m && j < n) {
                pq.offer(result[i][j]);
                i++;
                j++;
            }
            
            i = startI;
            j = startJ;
            while (i < m && j < n) {
                result[i][j] = pq.poll();
                i++;
                j++;
            }
        }
        
        return result;
    }
}