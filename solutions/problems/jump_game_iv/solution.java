class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length;
        if (n == 1) return 0;
        
        // สร้าง map จัดกลุ่ม indices ตามค่า
        Map<Integer, List<Integer>> groups = new HashMap<>();
        for (int i = 0; i < n; i++) {
            groups.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
        }
        
        int[] dist = new int[n];
        Arrays.fill(dist, -1);
        Queue<Integer> queue = new LinkedList<>();
        
        queue.offer(0);
        dist[0] = 0;
        
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            
            if (curr == n - 1) {
                return dist[curr];
            }
            
            // กระโดดไป curr+1
            if (curr + 1 < n && dist[curr + 1] == -1) {
                dist[curr + 1] = dist[curr] + 1;
                queue.offer(curr + 1);
            }
            
            // กระโดดไป curr-1
            if (curr - 1 >= 0 && dist[curr - 1] == -1) {
                dist[curr - 1] = dist[curr] + 1;
                queue.offer(curr - 1);
            }
            
            // กระโดดไป indices ที่มีค่าเท่ากัน
            int val = arr[curr];
            if (groups.containsKey(val)) {
                for (int next : groups.get(val)) {
                    if (dist[next] == -1) {
                        dist[next] = dist[curr] + 1;
                        queue.offer(next);
                    }
                }
                // ลบกลุ่มนี้เพื่อไม่ให้เยือนซ้ำ (optimization สำคัญ!)
                groups.remove(val);
            }
        }
        
        return -1;
    }
}