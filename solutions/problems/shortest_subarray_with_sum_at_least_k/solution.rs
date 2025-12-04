impl Solution {
    pub fn shortest_subarray(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let k = k as i64;
        
        // สร้าง prefix sums
        let mut prefix = vec![0i64; n + 1];
        for i in 0..n {
            prefix[i + 1] = prefix[i] + nums[i] as i64;
        }
        
        let mut deque = std::collections::VecDeque::new();
        let mut min_length = i32::MAX;
        
        for i in 0..=n {
            // ลบ index ที่ทำให้ prefix[current] <= prefix[back]
            while !deque.is_empty() && prefix[i] <= prefix[*deque.back().unwrap()] {
                deque.pop_back();
            }
            
            // เพิ่ม current index
            deque.push_back(i);
            
            // ตรวจสอบจากด้านหน้า
            while !deque.is_empty() && prefix[i] - prefix[*deque.front().unwrap()] >= k {
                let length = i - deque.pop_front().unwrap();
                min_length = min_length.min(length as i32);
            }
        }
        
        if min_length == i32::MAX { -1 } else { min_length }
    }
}