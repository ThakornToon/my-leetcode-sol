impl Solution {
    pub fn max_subarray_sum_circular(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut total = 0;
        let mut max_sum = i32::MIN;
        let mut min_sum = i32::MAX;
        let mut current_max = 0;
        let mut current_min = 0;
        
        for &num in &nums {
            total += num;
            
            // Kadane's algorithm for max subarray
            current_max = (current_max + num).max(num);
            max_sum = max_sum.max(current_max);
            
            // Kadane's algorithm for min subarray
            current_min = (current_min + num).min(num);
            min_sum = min_sum.min(current_min);
        }
        
        // ถ้า array มีแต่ค่าลบ
        if max_sum < 0 {
            return max_sum;
        }
        
        // หาค่าสูงสุดระหว่าง non-circular กับ circular
        max_sum.max(total - min_sum)
    }
}