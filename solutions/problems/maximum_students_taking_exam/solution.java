class Solution {
    public int maxStudents(char[][] seats) {
        int m = seats.length;
        int n = seats[0].length;
        int maxMask = 1 << n;
        
        int[] broken = new int[m];
        for (int i = 0; i < m; i++) {
            int mask = 0;
            for (int j = 0; j < n; j++) {
                if (seats[i][j] == '#') {
                    mask |= (1 << j);
                }
            }
            broken[i] = mask;
        }
        
        Integer[][] memo = new Integer[m + 1][maxMask];
        
        return dfs(0, 0, broken, memo, n);
    }
    
    private int dfs(int row, int prevMask, int[] broken, Integer[][] memo, int n) {
        if (row == broken.length) return 0;
        if (memo[row][prevMask] != null) return memo[row][prevMask];
        
        int res = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if ((mask & broken[row]) != 0) continue;
            if ((mask & (mask << 1)) != 0) continue;
            if ((prevMask & (mask << 1)) != 0) continue;
            if ((prevMask & (mask >> 1)) != 0) continue;
            
            int cnt = Integer.bitCount(mask);
            res = Math.max(res, cnt + dfs(row + 1, mask, broken, memo, n));
        }
        
        memo[row][prevMask] = res;
        return res;
    }
}