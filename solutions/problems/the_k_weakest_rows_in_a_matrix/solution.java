class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int m = mat.length;
        int[][] rows = new int[m][2];
        
        for (int i = 0; i < m; i++) {
            rows[i][0] = (int)Arrays.stream(mat[i]).filter(x -> x == 1).count();
            rows[i][1] = i;
        }
        
        Arrays.sort(rows, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        
        return Arrays.stream(rows, 0, k).mapToInt(r -> r[1]).toArray();
    }
}