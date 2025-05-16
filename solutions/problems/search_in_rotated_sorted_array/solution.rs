impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut low: usize = 0;
        let mut high: usize = nums.len() - 1;

        while low <= high {
            let mid: usize = (low + high) / 2;

            if nums[mid] == target {
                return mid as i32;
            }

            if nums[low] <= nums[mid] {
                if nums[low] <= target && target < nums[mid] {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if nums[mid] < target && target <= nums[high] {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
}