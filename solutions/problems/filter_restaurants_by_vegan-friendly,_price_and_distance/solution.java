class Solution {
    public List<Integer> filterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        List<int[]> filtered = new ArrayList<>();
        
        for (int[] r : restaurants) {
            int id = r[0];
            int rating = r[1];
            int vf = r[2];
            int price = r[3];
            int distance = r[4];
            
            if (veganFriendly == 1 && vf == 0) continue;
            if (price > maxPrice) continue;
            if (distance > maxDistance) continue;
            
            filtered.add(new int[]{rating, id});
        }
        
        // เรียงลำดับ: rating desc, id desc
        filtered.sort((a, b) -> {
            if (a[0] != b[0]) {
                return b[0] - a[0];  // rating desc
            }
            return b[1] - a[1];  // id desc
        });
        
        List<Integer> result = new ArrayList<>();
        for (int[] f : filtered) {
            result.add(f[1]);
        }
        
        return result;
    }
}