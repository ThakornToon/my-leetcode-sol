impl Solution {
    pub fn min_increment_for_unique(nums: Vec<i32>) -> i32 {
        let max_val = *nums.iter().max().unwrap_or(&0) as usize;
        let n = nums.len();
        
        // สร้าง array สำหรับนับความถี่
        let mut count = vec![0; max_val + n + 1];
        
        // นับความถี่
        for &num in &nums {
            count[num as usize] += 1;
        }
        
        let mut moves = 0;
        
        // ตรวจสอบทุกตำแหน่ง
        for i in 0..count.len() - 1 {
            if count[i] > 1 {
                let duplicates = count[i] - 1;
                count[i + 1] += duplicates;
                moves += duplicates as i32;
            }
        }
        
        moves
    }
}