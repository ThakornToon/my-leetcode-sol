impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let mut squares: Vec<i32> = nums.iter().map(|&x| x * x).collect();
        squares.sort_unstable();
        squares
    }
}