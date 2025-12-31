impl Solution {
    pub fn equal_substring(s: String, t: String, max_cost: i32) -> i32 {
        let s_chars: Vec<char> = s.chars().collect();
        let t_chars: Vec<char> = t.chars().collect();
        let n = s_chars.len();
        
        let mut max_length = 0;
        let mut current_cost = 0;
        let mut left = 0;
        
        for right in 0..n {
            // คำนวณค่าใช้จ่าย
            let cost = (s_chars[right] as i32 - t_chars[right] as i32).abs();
            current_cost += cost;
            
            // ขยับหน้าต่างซ้ายถ้าเกิน budget
            while current_cost > max_cost {
                let left_cost = (s_chars[left] as i32 - t_chars[left] as i32).abs();
                current_cost -= left_cost;
                left += 1;
            }
            
            // อัปเดตความยาวสูงสุด
            max_length = max_length.max((right - left + 1) as i32);
        }
        
        max_length
    }
}