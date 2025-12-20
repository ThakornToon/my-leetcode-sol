impl Solution {
    pub fn max_sum_two_no_overlap(nums: Vec<i32>, first_len: i32, second_len: i32) -> i32 {
        let n = nums.len();
        let first_len = first_len as usize;
        let second_len = second_len as usize;
        
        // Build prefix sum
        let mut prefix = vec![0; n + 1];
        for i in 0..n {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        let get_sum = |l: usize, r: usize| -> i32 {
            prefix[r + 1] - prefix[l]
        };
        
        let mut result = 0;
        
        // Case 1: first_len before second_len
        let mut max_first = 0;
        for i in (first_len + second_len - 1)..n {
            // Update max of first_len ending before second_len
            let first_end = i - second_len;
            let first_start = first_end - first_len + 1;
            max_first = max_first.max(get_sum(first_start, first_end));
            
            // Second subarray
            let second_sum = get_sum(i - second_len + 1, i);
            result = result.max(max_first + second_sum);
        }
        
        // Case 2: second_len before first_len
        let mut max_second = 0;
        for i in (first_len + second_len - 1)..n {
            // Update max of second_len ending before first_len
            let second_end = i - first_len;
            let second_start = second_end - second_len + 1;
            max_second = max_second.max(get_sum(second_start, second_end));
            
            // First subarray
            let first_sum = get_sum(i - first_len + 1, i);
            result = result.max(max_second + first_sum);
        }
        
        result
    }
}