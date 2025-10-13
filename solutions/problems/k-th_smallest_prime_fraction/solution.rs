impl Solution {
    pub fn kth_smallest_prime_fraction(arr: Vec<i32>, k: i32) -> Vec<i32> {
        let n = arr.len();
        let mut left = 0.0;
        let mut right = 1.0;
        
        while left < right {
            let mid = (left + right) / 2.0;
            let mut count = 0;
            let mut i = 0;
            let mut max_fraction = 0.0;
            let (mut numerator, mut denominator) = (0, 0);
            
            for j in 1..n {
                while i < j && (arr[i] as f64) / (arr[j] as f64) <= mid {
                    let fraction = arr[i] as f64 / arr[j] as f64;
                    if fraction > max_fraction {
                        max_fraction = fraction;
                        numerator = arr[i];
                        denominator = arr[j];
                    }
                    i += 1;
                }
                count += i;
            }
            
            match count.cmp(&(k as usize)) {
                std::cmp::Ordering::Equal => return vec![numerator, denominator],
                std::cmp::Ordering::Less => left = mid,
                std::cmp::Ordering::Greater => right = mid,
            }
        }
        
        vec![]
    }
}