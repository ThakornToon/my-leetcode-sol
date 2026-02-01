class Solution {
    public int minimumCost(int[] nums) {
        int n = nums.length;
        int min1 = Integer.MAX_VALUE;
        int min2 = Integer.MAX_VALUE;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < min1) {
                min2 = min1;      // อัปเดตรองน้อยที่สุด
                min1 = nums[i];   // อัปเดตน้อยที่สุด
            } else if (nums[i] < min2) {
                min2 = nums[i];   // อัปเดตรองน้อยที่สุด
            }
        }
        
        return nums[0] + min1 + min2;
    }
}