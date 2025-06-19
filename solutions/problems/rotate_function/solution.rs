impl Solution {
    pub fn max_rotate_function(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n == 0 {
            return 0;
        }
        
        let mut sum = 0;
        let mut f = 0;
        
        // คำนวณ sum ของอาร์เรย์และ F(0)
        for i in 0..n {
            sum += nums[i];
            f += i as i32 * nums[i];
        }
        
        let mut max_f = f;
        
        // คำนวณ F(k) สำหรับ k = 1..n-1 โดยใช้สูตร recurrence F(k) = F(k-1) + sum - n * nums[n-k]
        for k in 1..n {
            f = f + sum - n as i32 * nums[n - k];
            if f > max_f {
                max_f = f;
            }
        }
        
        max_f
    }
}