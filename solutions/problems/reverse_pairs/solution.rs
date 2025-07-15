impl Solution {
    fn merge_and_count(nums: &mut Vec<i32>, start: usize, mid: usize, end: usize) -> i32 {
        let mut count = 0;
        let mut j = mid + 1;
        
        // นับ Reverse Pairs
        for i in start..=mid {
            while j <= end && nums[i] as i64 > 2 * nums[j] as i64 {
                j += 1;
            }
            count += (j - (mid + 1)) as i32;
        }
        
        // Merge ส่วนที่เรียงแล้ว
        let mut temp = Vec::with_capacity(end - start + 1);
        let mut i = start;
        let mut j = mid + 1;
        
        while i <= mid && j <= end {
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
        
        while j <= end {
            temp.push(nums[j]);
            j += 1;
        }
        
        for (p, &num) in temp.iter().enumerate() {
            nums[start + p] = num;
        }
        
        count
    }
    
    fn merge_sort(nums: &mut Vec<i32>, start: usize, end: usize) -> i32 {
        if start >= end {
            return 0;
        }
        
        let mid = start + (end - start) / 2;
        let mut count = 0;
        
        count += Solution::merge_sort(nums, start, mid);
        count += Solution::merge_sort(nums, mid + 1, end);
        count += Solution::merge_and_count(nums, start, mid, end);
        
        count
    }

    pub fn reverse_pairs(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let len = nums.len() - 1;
        Solution::merge_sort(&mut nums, 0, len)
    }
}