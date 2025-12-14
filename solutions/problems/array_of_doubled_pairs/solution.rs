impl Solution {
    pub fn can_reorder_doubled(arr: Vec<i32>) -> bool {
        let n = arr.len();
        if n % 2 != 0 {
            return false;
        }
        
        // เรียงตามค่าสัมบูรณ์
        let mut sorted_arr = arr;
        sorted_arr.sort_by_key(|&x| x.abs());
        
        use std::collections::HashMap;
        let mut count: HashMap<i32, i32> = HashMap::new();
        
        // นับความถี่
        for &num in &sorted_arr {
            *count.entry(num).or_insert(0) += 1;
        }
        
        // ตรวจสอบทีละตัวตามลำดับที่เรียงแล้ว
        for &num in &sorted_arr {
            let cnt = match count.get(&num) {
                Some(&c) if c > 0 => c,
                _ => continue,
            };
            
            let target = num * 2;
            
            match count.get(&target) {
                Some(&target_cnt) if target_cnt > 0 => {
                    // ลดจำนวนทั้งสองตัว
                    *count.get_mut(&num).unwrap() -= 1;
                    *count.get_mut(&target).unwrap() -= 1;
                }
                _ => return false,
            }
        }
        
        true
    }
}