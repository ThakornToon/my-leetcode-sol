use std::cmp::min;
impl Solution {
    pub fn find_kth_number(m: i32, n: i32, k: i32) -> i32 {
        if m > n {
            let (m, n) = (n, m);
        }
        let mut left = 1;
        let mut right = m * n;
        
        while left < right {
            let mid = left + (right - left) / 2;
            let count = Self::count_less_equal(m, n, mid);
            if count < k {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        left
    }
    
    fn count_less_equal(m: i32, n: i32, target: i32) -> i32 {
        let mut count = 0;
        for i in 1..=m {
            // ในแถวที่ i, จำนวน column ที่ i*j ≤ target
            count += min(target / i, n);
        }
        count
    }
}