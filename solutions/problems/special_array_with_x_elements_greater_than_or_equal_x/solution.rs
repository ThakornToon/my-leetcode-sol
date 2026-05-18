impl Solution {
    pub fn special_array(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();
        let n = nums.len();
        
        // ทดสอบ x จาก 0 ถึง n
        for x in 0..=n {
            // binary search หาตัวแรกที่ >= x
            let pos = nums.partition_point(|&v| v < x as i32);
            let count = n - pos;
            
            if count == x {
                return x as i32;
            }
        }
        
        -1
    }
}