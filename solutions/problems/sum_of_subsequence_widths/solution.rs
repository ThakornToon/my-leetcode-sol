impl Solution {
    pub fn sum_subseq_widths(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();
        let n = nums.len();
        let mod_val = 1_000_000_007;
        
        // สร้าง powers of 2
        let mut pow2 = vec![1; n];
        for i in 1..n {
            pow2[i] = (pow2[i-1] * 2) % mod_val;
        }
        
        let mut sum: i64 = 0;
        for i in 0..n {
            sum = (sum + nums[i] as i64 * pow2[i] as i64) % mod_val;
            sum = (sum - nums[i] as i64 * pow2[n-1-i] as i64) % mod_val;
        }
        
        ((sum + mod_val) % mod_val) as i32
    }
}