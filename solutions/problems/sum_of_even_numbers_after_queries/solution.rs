impl Solution {
    pub fn sum_even_after_queries(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut nums = nums;
        let mut even_sum: i32 = nums.iter().filter(|&x| x % 2 == 0).sum();
        let mut result = Vec::with_capacity(queries.len());
        
        for query in queries {
            let val = query[0];
            let idx = query[1] as usize;
            
            // ถ้าค่าเดิมเป็นเลขคู่
            if nums[idx] % 2 == 0 {
                even_sum -= nums[idx];
            }
            
            // อัพเดตค่า
            nums[idx] += val;
            
            // ถ้าค่าใหม่เป็นเลขคู่
            if nums[idx] % 2 == 0 {
                even_sum += nums[idx];
            }
            
            result.push(even_sum);
        }
        
        result
    }
}