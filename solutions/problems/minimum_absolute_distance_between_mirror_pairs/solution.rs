use std::collections::HashMap;

impl Solution {
    fn reverse_num(mut num: i32) -> i32 {
        let mut rev = 0;
        while num > 0 {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        rev
    }
    
    pub fn min_mirror_pair_distance(nums: Vec<i32>) -> i32 {
        let mut mirror_map = HashMap::new();
        let mut min_dist = i32::MAX;
        
        for (i, &num) in nums.iter().enumerate() {
            let mirror = Self::reverse_num(num);
            
            // ตรวจสอบว่า num เป็น mirror ของตัวก่อนหน้าหรือไม่
            if let Some(&prev) = mirror_map.get(&num) {
                min_dist = min_dist.min((i - prev) as i32);
            }
            
            mirror_map.insert(mirror, i);
        }
        
        if min_dist == i32::MAX { -1 } else { min_dist }
    }
}