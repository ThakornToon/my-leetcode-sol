impl Solution {
    pub fn wiggle_sort(nums: &mut Vec<i32>) {
        nums.sort();
        let mut temp = nums.clone();
        let half = (nums.len() + 1) / 2;
        
        let mut small = half - 1;
        let mut large = nums.len() - 1;
        
        for i in 0..nums.len() {
            if i % 2 == 0 {
                nums[i] = temp[small];
                small -= 1;
            } else {
                nums[i] = temp[large];
                large -= 1;
            }
        }
    }
}