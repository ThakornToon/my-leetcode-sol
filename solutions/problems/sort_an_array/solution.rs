impl Solution {
    pub fn sort_array(nums: Vec<i32>) -> Vec<i32> {
        let len = nums.len();
        let mut nums = nums;
        Self::merge_sort(&mut nums, 0, len - 1);
        nums
    }
    
    fn merge_sort(nums: &mut Vec<i32>, left: usize, right: usize) {
        if left >= right {
            return;
        }
        
        let mid = left + (right - left) / 2;
        Self::merge_sort(nums, left, mid);
        Self::merge_sort(nums, mid + 1, right);
        Self::merge(nums, left, mid, right);
    }
    
    fn merge(nums: &mut Vec<i32>, left: usize, mid: usize, right: usize) {
        let mut temp = Vec::with_capacity(right - left + 1);
        let (mut i, mut j) = (left, mid + 1);
        
        while i <= mid && j <= right {
            if nums[i] <= nums[j] {
                temp.push(nums[i]);
                i += 1;
            } else {
                temp.push(nums[j]);
                j += 1;
            }
        }
        
        while i <= mid {
            temp.push(nums[i]);
            i += 1;
        }
        
        while j <= right {
            temp.push(nums[j]);
            j += 1;
        }
        
        for (k, &value) in temp.iter().enumerate() {
            nums[left + k] = value;
        }
    }
}