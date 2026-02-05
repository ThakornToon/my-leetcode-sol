class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            
            if (val == 0) {
                result[i] = 0;
            } else if (val > 0) {
                // เลื่อนขวา
                int newIndex = (i + val) % n;
                result[i] = nums[newIndex];
            } else {
                // เลื่อนซ้าย
                int steps = Math.abs(val);
                steps = steps % n;  // ลด steps
                int newIndex = (i - steps + n) % n;
                result[i] = nums[newIndex];
            }
        }
        
        return result;
    }
}