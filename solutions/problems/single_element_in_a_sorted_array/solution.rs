impl Solution {
    pub fn single_non_duplicate(nums: Vec<i32>) -> i32 {
        let mut low = 0;
        let mut high = nums.len() - 1;
        
        while low < high {
            let mid = low + (high - low) / 2;
            if nums[mid] == nums[mid ^ 1] {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        nums[low]
    }
}