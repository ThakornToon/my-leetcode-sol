use std::collections::HashMap;
impl Solution {
    pub fn four_sum_count(nums1: Vec<i32>, nums2: Vec<i32>, nums3: Vec<i32>, nums4: Vec<i32>) -> i32 {
        let mut sum_map = HashMap::new();
        let mut count = 0;

        // คำนวณผลรวมจาก nums1 และ nums2
        for &a in &nums1 {
            for &b in &nums2 {
                *sum_map.entry(a + b).or_insert(0) += 1;
            }
        }

        // ตรวจสอบผลรวมจาก nums3 และ nums4
        for &c in &nums3 {
            for &d in &nums4 {
                let target = -(c + d);
                if let Some(&val) = sum_map.get(&target) {
                    count += val;
                }
            }
        }

        count
    }
}