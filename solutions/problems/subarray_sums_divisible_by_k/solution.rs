impl Solution {
    pub fn subarrays_div_by_k(nums: Vec<i32>, k: i32) -> i32 {
        let k = k as usize;
        let mut mod_count = vec![0; k];
        mod_count[0] = 1; // prefix sum ว่าง
        
        let mut prefix_sum = 0;
        let mut count = 0;
        
        for num in nums {
            prefix_sum += num;
            
            // ปรับ remainder ให้เป็นบวก
            let mut remainder = prefix_sum % k as i32;
            if remainder < 0 {
                remainder += k as i32;
            }
            
            let remainder = remainder as usize;
            count += mod_count[remainder];
            mod_count[remainder] += 1;
        }
        
        count
    }
}