class Solution {
    public int minPairSum(int[] nums) {
        // 1. เรียงลำดับอาร์เรย์
        Arrays.sort(nums);
        
        // 2. ใช้ two pointers หาผลรวมคู่
        int left = 0;
        int right = nums.length - 1;
        int maxPairSum = 0;
        
        while (left < right) {
            int currentSum = nums[left] + nums[right];
            maxPairSum = Math.max(maxPairSum, currentSum);
            
            left++;
            right--;
        }
        
        return maxPairSum;
    }
}