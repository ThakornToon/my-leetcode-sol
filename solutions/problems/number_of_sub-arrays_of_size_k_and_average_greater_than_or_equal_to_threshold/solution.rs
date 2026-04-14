impl Solution {
    pub fn num_of_subarrays(arr: Vec<i32>, k: i32, threshold: i32) -> i32 {
        let k = k as usize;
        let target_sum = k as i32 * threshold;
        
        arr.windows(k)
            .filter(|window| window.iter().sum::<i32>() >= target_sum)
            .count() as i32
    }
}