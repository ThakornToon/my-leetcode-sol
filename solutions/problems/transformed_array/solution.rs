impl Solution {
    pub fn construct_transformed_array(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut result = vec![0; n];
        
        for i in 0..n {
            let val = nums[i];
            
            if val == 0 {
                result[i] = 0;
            } else if val > 0 {
                // เลื่อนขวา
                let steps = val as usize;
                let new_index = (i + steps) % n;
                result[i] = nums[new_index];
            } else {
                // เลื่อนซ้าย
                let steps = val.abs() as usize;
                let steps_reduced = steps % n;
                let new_index = (i as i32 - steps_reduced as i32 + n as i32) as usize % n;
                result[i] = nums[new_index];
            }
        }
        
        result
    }
}