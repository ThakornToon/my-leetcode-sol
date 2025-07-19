impl Solution {
    pub fn optimal_division(nums: Vec<i32>) -> String {
        match nums.len() {
            1 => nums[0].to_string(),
            2 => format!("{}/{}", nums[0], nums[1]),
            _ => {
                let denominator = nums[1..]
                    .iter()
                    .map(|n| n.to_string())
                    .collect::<Vec<String>>()
                    .join("/");
                    
                format!("{}/({})", nums[0], denominator)
            }
        }
    }
}