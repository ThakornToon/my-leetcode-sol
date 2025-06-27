impl Solution {
    fn merge_sort(
        nums: &mut Vec<(i32, usize)>,
        counts: &mut Vec<i32>,
        temp: &mut Vec<(i32, usize)>,
        left: usize,
        right: usize,
    ) {
        if left >= right {
            return;
        }
        
        let mid = left + (right - left) / 2;
        Self::merge_sort(nums, counts, temp, left, mid);
        Self::merge_sort(nums, counts, temp, mid + 1, right);
        
        let mut i = left;
        let mut j = mid + 1;
        let mut k = left;
        let mut right_count = 0;
        
        while i <= mid && j <= right {
            if nums[i].0 > nums[j].0 {
                right_count += 1;
                temp[k] = nums[j];
                j += 1;
            } else {
                counts[nums[i].1] += right_count;
                temp[k] = nums[i];
                i += 1;
            }
            k += 1;
        }
        
        while i <= mid {
            counts[nums[i].1] += right_count;
            temp[k] = nums[i];
            i += 1;
            k += 1;
        }
        
        while j <= right {
            temp[k] = nums[j];
            j += 1;
            k += 1;
        }
        
        for idx in left..=right {
            nums[idx] = temp[idx];
        }
    }

    pub fn count_smaller(nums: Vec<i32>) -> Vec<i32> {
        let mut nums_with_index: Vec<(i32, usize)> = nums.iter().enumerate().map(|(i, &val)| (val, i)).collect();
        
        let mut counts = vec![0; nums.len()];
        let mut temp = vec![(0, 0); nums.len()];
        
        Self::merge_sort(&mut nums_with_index, &mut counts, &mut temp, 0, nums.len() - 1);
        
        counts
    }
}