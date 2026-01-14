impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        use std::collections::VecDeque;
        
        let n = nums.len();
        let k = k as usize;
        
        if n == 0 || k == 0 {
            return Vec::new();
        }
        
        let mut result = Vec::with_capacity(n - k + 1);
        let mut deque = VecDeque::new();
        
        for i in 0..n {
            // ลบ index ที่อยู่นอกหน้าต่างจากด้านหน้า
            if let Some(&front) = deque.front() {
                if front + k <= i {
                    deque.pop_front();
                }
            }
            
            // รักษา deque ให้เป็น decreasing order
            while let Some(&back) = deque.back() {
                if nums[back] <= nums[i] {
                    deque.pop_back();
                } else {
                    break;
                }
            }
            
            // เพิ่ม index ปัจจุบัน
            deque.push_back(i);
            
            // บันทึกผลลัพธ์เมื่อผ่านหน้าต่างแรกแล้ว
            if i >= k - 1 {
                result.push(nums[*deque.front().unwrap()]);
            }
        }
        
        result
    }
}