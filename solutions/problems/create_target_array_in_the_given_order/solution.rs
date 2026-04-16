impl Solution {
    pub fn create_target_array(nums: Vec<i32>, index: Vec<i32>) -> Vec<i32> {
        let mut target = Vec::new();
        
        for (i, &val) in nums.iter().enumerate() {
            let pos = index[i] as usize;
            target.insert(pos, val);
        }
        
        target
    }
}