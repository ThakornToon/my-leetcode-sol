class Solution {
    public int minFlips(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int totalCells = m * n;
        
        // แปลง matrix เป็น bitmask
        int startMask = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    int pos = i * n + j;
                    startMask |= (1 << pos);
                }
            }
        }
        
        // ถ้าเป็น 0 หมดแล้ว
        if (startMask == 0) {
            return 0;
        }
        
        // BFS
        Queue<int[]> queue = new LinkedList<>();  // {mask, steps}
        Set<Integer> visited = new HashSet<>();
        
        queue.offer(new int[]{startMask, 0});
        visited.add(startMask);
        
        int[][] dirs = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int mask = current[0];
            int steps = current[1];
            
            // ลอง flip ทุกตำแหน่ง
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int newMask = mask;
                    
                    // flip ตำแหน่ง i,j และเพื่อนบ้าน
                    for (int[] dir : dirs) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            int pos = ni * n + nj;
                            newMask ^= (1 << pos);
                        }
                    }
                    
                    if (newMask == 0) {
                        return steps + 1;
                    }
                    
                    if (!visited.contains(newMask)) {
                        visited.add(newMask);
                        queue.offer(new int[]{newMask, steps + 1});
                    }
                }
            }
        }
        
        return -1;
    }
}