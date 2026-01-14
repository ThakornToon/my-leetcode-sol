class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] result = new int[n - k + 1];
        Deque<Integer> deque = new ArrayDeque<>();  // เก็บ index ของ elements
        
        for (int i = 0; i < n; i++) {
            // Step 1: ลบ index ที่อยู่นอกหน้าต่างจากด้านหน้า
            if (!deque.isEmpty() && deque.peekFirst() == i - k) {
                deque.pollFirst();
            }
            
            // Step 2: ลบ elements จากด้านหลังที่น้อยกว่า nums[i]
            while (!deque.isEmpty() && nums[deque.peekLast()] <= nums[i]) {
                deque.pollLast();
            }
            
            // Step 3: เพิ่ม index ปัจจุบัน
            deque.offerLast(i);
            
            // Step 4: บันทึกค่าสูงสุดเมื่อผ่านหน้าต่างแรกแล้ว
            if (i >= k - 1) {
                result[i - k + 1] = nums[deque.peekFirst()];
            }
        }
        
        return result;
    }
}