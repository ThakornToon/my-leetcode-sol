class Solution {
    public int minimumDistance(int[] nums) {
        int n = nums.length;
        Map<Integer, List<Integer>> positions = new HashMap<>();
        
        // เก็บตำแหน่งของแต่ละค่า
        for (int i = 0; i < n; i++) {
            positions.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }
        
        int minDist = Integer.MAX_VALUE;
        
        // สำหรับแต่ละค่าที่มีอย่างน้อย 3 ตัว
        for (List<Integer> pos : positions.values()) {
            int m = pos.size();
            if (m < 3) continue;
            
            // ระยะทาง = 2*(pos[c] - pos[a]) สำหรับ a < b < c
            // ต้องการ a และ c ที่ใกล้กันที่สุด
            // เนื่องจาก c - a >= 2 เสมอ (มี b ระหว่าง)
            for (int a = 0; a < m - 2; a++) {
                int c = a + 2;
                int dist = 2 * (pos.get(c) - pos.get(a));
                minDist = Math.min(minDist, dist);
            }
        }
        
        return minDist == Integer.MAX_VALUE ? -1 : minDist;
    }
}