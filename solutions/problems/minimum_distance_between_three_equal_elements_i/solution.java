class Solution {
    public int minimumDistance(int[] nums) {
        int n = nums.length;
        Map<Integer, List<Integer>> positions = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int val = nums[i];
            List<Integer> list = positions.get(val);
            if (list == null) {
                list = new ArrayList<>();
                positions.put(val, list);
            }
            list.add(i);
        }
        
        int minDist = Integer.MAX_VALUE;
        
        for (List<Integer> pos : positions.values()) {
            int m = pos.size();
            if (m < 3) continue;
            
            // แค่หาคู่ที่ใกล้ที่สุดของ i และ k
            for (int a = 0; a < m - 2; a++) {
                int c = a + 2;
                int dist = 2 * (pos.get(c) - pos.get(a));
                minDist = Math.min(minDist, dist);
            }
        }
        
        return minDist == Integer.MAX_VALUE ? -1 : minDist;
    }
}