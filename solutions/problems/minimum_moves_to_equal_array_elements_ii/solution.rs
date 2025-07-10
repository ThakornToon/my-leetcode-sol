impl Solution {
    pub fn min_moves2(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();  // เรียงลำดับอาร์เรย์
        
        let median = nums[nums.len() / 2];  // หาค่ามัธยฐาน
        let mut moves = 0;
        
        // คำนวณผลรวมความแตกต่างจากมัธยฐาน
        for &num in &nums {
            moves += (num - median).abs();
        }
        
        moves
    }
}