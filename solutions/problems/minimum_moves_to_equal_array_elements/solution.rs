impl Solution {
    pub fn min_moves(nums: Vec<i32>) -> i32 {
        // หาค่าต่ำสุด
        let min_num = nums.iter().min().unwrap_or(&0);
        
        // คำนวณผลรวมของผลต่าง
        nums.iter().map(|x| x - min_num).sum()
    }
}