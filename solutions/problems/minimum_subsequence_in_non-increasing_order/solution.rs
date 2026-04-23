impl Solution {
    pub fn min_subsequence(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        // เรียงจากมากไปน้อย
        nums.sort_by(|a, b| b.cmp(a));
        
        let total_sum: i32 = nums.iter().sum();
        let mut sub_sum = 0;
        let mut result = Vec::new();
        
        for &num in &nums {
            sub_sum += num;
            result.push(num);
            if sub_sum > total_sum - sub_sum {
                break;
            }
        }
        
        result
    }
}