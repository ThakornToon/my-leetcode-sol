use std::collections::HashMap;
impl Solution {
    pub fn contains_nearby_almost_duplicate(nums: Vec<i32>, index_diff: i32, value_diff: i32) -> bool {
        let bucket_size = (value_diff as i64) + 1;
        let mut buckets: HashMap<i64, i64> = HashMap::new();

        for (i, &num) in nums.iter().enumerate() {
            let num = num as i64;
            let bucket_id = if num < 0 {
                (num + 1) / bucket_size - 1
            } else {
                num / bucket_size
            };

            // ตรวจสอบ bucket เดียวกัน
            if buckets.contains_key(&bucket_id) {
                return true;
            }

            // ตรวจสอบ bucket ข้างเคียง
            if let Some(&val) = buckets.get(&(bucket_id - 1)) {
                if (val - num).abs() <= value_diff as i64 {
                    return true;
                }
            }

            if let Some(&val) = buckets.get(&(bucket_id + 1)) {
                if (val - num).abs() <= value_diff as i64 {
                    return true;
                }
            }

            // เพิ่มค่าเข้า bucket
            buckets.insert(bucket_id, num);

            // ลบค่าที่อยู่นอก sliding window
            if i >= index_diff as usize {
                let old_num = nums[i - index_diff as usize] as i64;
                let old_bucket_id = if old_num < 0 {
                    (old_num + 1) / bucket_size - 1
                } else {
                    old_num / bucket_size
                };
                buckets.remove(&old_bucket_id);
            }
        }

        false
    }
}