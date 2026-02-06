class Solution {
    public int minRemoval(int[] nums, int k) {
        int n = nums.length;
        if (n <= 1) return 0;  // อาร์เรย์ขนาด 1 สมดุลเสมอ
        
        // 1. เรียงลำดับอาร์เรย์
        Arrays.sort(nums);
        
        // 2. Sliding window
        int left = 0;
        int maxLength = 1;  // อย่างน้อย 1 ตัว
        
        for (int right = 0; right < n; right++) {
            // ขยาย right ตราบใดที่ตรงเงื่อนไข
            // เงื่อนไข: nums[right] <= k * nums[left]
            while (left <= right && nums[right] > (long)k * nums[left]) {
                left++;
            }
            
            // อัปเดตความยาวช่วงที่ยาวที่สุด
            maxLength = Math.max(maxLength, right - left + 1);
        }
        
        // 3. จำนวนที่ต้องลบ
        return n - maxLength;
    }
}