class Solution {
    public int minimumDifference(int[] nums, int k) {
        int n = nums.length;
        
        // กรณีพิเศษ
        if (k == 1 || n <= 1) {
            return 0;
        }
        
        // 1. เรียงลำดับอาร์เรย์
        Arrays.sort(nums);
        
        // 2. ใช้ sliding window
        int minDiff = Integer.MAX_VALUE;
        
        for (int i = 0; i <= n - k; i++) {
            int diff = nums[i + k - 1] - nums[i];
            minDiff = Math.min(minDiff, diff);
        }
        
        return minDiff;
    }
}