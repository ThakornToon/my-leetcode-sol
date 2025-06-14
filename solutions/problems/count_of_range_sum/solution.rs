impl Solution {
    fn merge_and_count(sum: &mut Vec<i64>, left: usize, mid: usize, right: usize, lower: i64, upper: i64) -> i32 {
        let mut count: i32 = 0;
        let (mut j, mut k) = (mid + 1, mid + 1);
        
        for i in left..=mid {
            while j <= right && sum[j] - sum[i] < lower {
                j += 1;
            }
            while k <= right && sum[k] - sum[i] <= upper {
                k += 1;
            }
            count += (k - j) as i32;
        }
        
        // Merge
        let mut temp = Vec::with_capacity(right - left + 1);
        let (mut p, mut q) = (left, mid + 1);
        
        while p <= mid && q <= right {
            if sum[p] <= sum[q] {
                temp.push(sum[p]);
                p += 1;
            } else {
                temp.push(sum[q]);
                q += 1;
            }
        }
        
        while p <= mid {
            temp.push(sum[p]);
            p += 1;
        }
        
        while q <= right {
            temp.push(sum[q]);
            q += 1;
        }
        
        for (i, &val) in temp.iter().enumerate() {
            sum[left + i] = val;
        }
        
        return count;
    }

    fn merge_sort(sum: &mut Vec<i64>, left: usize, right: usize, lower: i64, upper: i64) -> i32 {
        if left >= right {
            return 0;
        }
        let mid = left + (right - left) / 2;
        return Self::merge_sort(sum, left, mid, lower, upper) + 
        Self::merge_sort(sum, mid + 1, right, lower, upper) +
        Self::merge_and_count(sum, left, mid, right, lower, upper);
    }
    pub fn count_range_sum(nums: Vec<i32>, lower: i32, upper: i32) -> i32 {
        let mut sum = vec![0];
        let mut current: i64 = 0 ;
        for &num in &nums {
            current += num as i64;
            sum.push(current);
        }
        let len = sum.len() - 1;
        return Self::merge_sort(&mut sum, 0, len, lower as i64, upper as i64);
    }
}