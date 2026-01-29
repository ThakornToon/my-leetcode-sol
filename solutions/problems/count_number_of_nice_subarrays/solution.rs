impl Solution {
    pub fn number_of_subarrays(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut count = vec![0; n + 1];
        count[0] = 1;
        
        let mut prefix = 0;
        let mut result = 0;
        
        for num in nums {
            prefix += (num % 2) as usize;
            
            if prefix >= k as usize {
                result += count[prefix - k as usize];
            }
            
            count[prefix] += 1;
        }
        
        result as i32
    }
}