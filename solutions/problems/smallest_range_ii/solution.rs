impl Solution {
    pub fn smallest_range_ii(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut nums = nums;
        nums.sort();
        
        let mut answer = nums[n-1] - nums[0];
        
        for i in 0..n-1 {
            let high = (nums[n-1] - k).max(nums[i] + k); // ตัวหลัง i ถูก - k
            let low = (nums[0] + k).min(nums[i+1] - k); // ตัวหน้า i+1 ถูก + k
            answer = answer.min(high - low);
        }
        
        answer
    }
}