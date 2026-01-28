class Solution {
    private int result;

    public int tilingRectangle(int n, int m) {
        if (n == m) return 1;
        
        if (n > m) {
            int temp = n;
            n = m;
            m = temp;
        }
        
        int[] rows = new int[n];
        int fullMask = (1 << m) - 1;
        result = Integer.MAX_VALUE;
        
        dfs(rows, n, m, 0, fullMask);
        return result;
    }
    
    private int[] findEmpty(int[] rows, int m, int fullMask) {
        for (int i = 0; i < rows.length; i++) {
            if (rows[i] != fullMask) {
                for (int j = 0; j < m; j++) {
                    if ((rows[i] & (1 << j)) == 0) {
                        return new int[]{i, j};
                    }
                }
            }
        }
        return new int[]{-1, -1};
    }
    
    private boolean canPlace(int[] rows, int x, int y, int size) {
        int squareMask = ((1 << size) - 1) << y;
        
        for (int i = 0; i < size; i++) {
            if ((rows[x + i] & squareMask) != 0) {
                return false;
            }
        }
        return true;
    }
    
    private void placeSquare(int[] rows, int x, int y, int size, boolean place) {
        int squareMask = ((1 << size) - 1) << y;
        
        if (place) {
            for (int i = 0; i < size; i++) {
                rows[x + i] |= squareMask;
            }
        } else {
            int clearMask = ~squareMask;
            for (int i = 0; i < size; i++) {
                rows[x + i] &= clearMask;
            }
        }
    }
    
    private void dfs(int[] rows, int n, int m, int count, int fullMask) {
        if (count >= result) return;
        
        int[] empty = findEmpty(rows, m, fullMask);
        int x = empty[0], y = empty[1];
        
        if (x == -1) {
            result = Math.min(result, count);
            return;
        }
        
        // หาขนาดสูงสุด
        int maxSize = Math.min(n - x, m - y);
        
        // ปรับ maxSize
        for (int size = 1; size <= maxSize; size++) {
            int mask = ((1 << size) - 1) << y;
            if ((rows[x + size - 1] & mask) != 0) {
                maxSize = size - 1;
                break;
            }
        }
        
        // ลองจากใหญ่ไปเล็ก
        for (int size = maxSize; size >= 1; size--) {
            if (canPlace(rows, x, y, size)) {
                placeSquare(rows, x, y, size, true);
                dfs(rows, n, m, count + 1, fullMask);
                placeSquare(rows, x, y, size, false);  // backtrack
            }
        }
    }
}