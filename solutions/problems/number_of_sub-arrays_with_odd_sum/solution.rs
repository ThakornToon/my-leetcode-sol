impl Solution {
    const MOD: i64 = 1_000_000_007;
    pub fn num_of_subarrays(arr: Vec<i32>) -> i32 {
        let mut odd_count = 0;
        let mut even_count = 1;
        let mut prefix_sum = 0;
        
        for &num in arr.iter() {
            prefix_sum += num as i64;
            if prefix_sum % 2 == 1 {
                odd_count += 1;
            } else {
                even_count += 1;
            }
        }
        
        ((odd_count * even_count) % Self::MOD) as i32
    }
}