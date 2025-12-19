impl Solution {
    pub fn prefixes_div_by5(nums: Vec<i32>) -> Vec<bool> {
        let mut answer = Vec::with_capacity(nums.len());
        let mut remainder = 0;
        
        for &num in &nums {
            remainder = (remainder * 2 + num) % 5;
            answer.push(remainder == 0);
        }
        
        answer
    }
}