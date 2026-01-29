class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        // count[prefix] = จำนวนครั้งที่ prefix sum นี้ปรากฏ
        Map<Integer, Integer> count = new HashMap<>();
        count.put(0, 1);  // prefix sum = 0 เกิดขึ้น 1 ครั้ง
        
        int prefix = 0;
        int result = 0;
        
        for (int num : nums) {
            // เพิ่ม prefix ถ้าเป็นเลขคี่
            prefix += num % 2;
            
            // ถ้ามี prefix - k ใน map, เพิ่มจำนวน subarrays
            if (count.containsKey(prefix - k)) {
                result += count.get(prefix - k);
            }
            
            // อัปเดต count สำหรับ prefix ปัจจุบัน
            count.put(prefix, count.getOrDefault(prefix, 0) + 1);
        }
        
        return result;
    }
}