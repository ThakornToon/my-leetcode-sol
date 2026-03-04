impl Solution {
    pub fn find_best_value(arr: Vec<i32>, target: i32) -> i32 {
        let mut arr = arr;
        arr.sort();
        let n = arr.len();
        
        // prefix sum
        let mut prefix = vec![0; n + 1];
        for i in 0..n {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        
        let mut left = 0;
        let mut right = *arr.last().unwrap();
        let mut best_value = 0;
        let mut min_diff = i32::MAX;
        
        while left <= right {
            let mid = left + (right - left) / 2;
            
            // binary search หาตำแหน่งแรกที่ > mid
            let pos = match arr.binary_search(&mid) {
                Ok(p) => p,
                Err(p) => p,
            };
            
            // คำนวณ sum
            let sum = prefix[pos] + (n - pos) as i32 * mid;
            let diff = (sum - target).abs();
            
            // อัปเดตค่าที่ดีที่สุด
            if diff < min_diff || (diff == min_diff && mid < best_value) {
                min_diff = diff;
                best_value = mid;
            }
            
            if sum < target {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        best_value
    }
}