impl Solution {
    pub fn largest_divisible_subset(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        nums.sort();
        let n = nums.len();
        let mut dp = vec![1; n];
        let mut from = vec![-1; n];
        let mut maxi = 0;
        
        for i in 0..n {
            for j in 0..i {
                if nums[i] % nums[j] == 0 {
                    if dp[i] < dp[j] + 1 {
                        dp[i] = dp[j] + 1;
                        from[i] = j as i32;
                    }
                }
            }
            if dp[maxi] < dp[i] {
                maxi = i;
            }
        }
        
        // สร้างผลลัพธ์
        let mut result = Vec::new();
        let mut current = maxi as i32;
        
        while current != -1 {
            result.push(nums[current as usize]);
            current = from[current as usize];
        }

        result
    }
}