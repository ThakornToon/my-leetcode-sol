class Solution {
    private int reverseNum(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        return rev;
    }
    
    public int minMirrorPairDistance(int[] nums) {
        Map<Integer, Integer> mirrorMap = new HashMap<>();
        int minDist = Integer.MAX_VALUE;
        
        for (int i = 0; i < nums.length; i++) {
            int mirror = reverseNum(nums[i]);
            
            // ตรวจสอบว่า nums[i] เป็น mirror ของตัวก่อนหน้าหรือไม่
            if (mirrorMap.containsKey(nums[i])) {
                minDist = Math.min(minDist, i - mirrorMap.get(nums[i]));
            }
            
            mirrorMap.put(mirror, i);
        }
        
        return minDist == Integer.MAX_VALUE ? -1 : minDist;
    }
}