impl Solution {
    fn getMax(nums: &Vec<i32>, start: usize, end:usize) -> i32 {
        let mut prevRob = 0;
        let mut maxRob = 0;

        for i in start..=end {
            let temp = maxRob.max(prevRob + nums[i]);
            prevRob = maxRob;
            maxRob = temp;
        }

        return maxRob;
    }    
    pub fn rob(nums: Vec<i32>) -> i32 {
        if (nums.len() == 1) {
            return nums[0];
        }
        return Self::getMax(&nums, 0, nums.len() - 2).max(Self::getMax(&nums, 1, nums.len() - 1));  
    }
}