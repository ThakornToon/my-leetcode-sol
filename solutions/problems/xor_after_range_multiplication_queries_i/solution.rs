const MOD: i64 = 1_000_000_007;

impl Solution {
    pub fn xor_after_queries(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> i32 {
        let mut arr: Vec<i64> = nums.iter().map(|&x| x as i64).collect();
        
        for q in queries {
            let li = q[0] as usize;
            let ri = q[1] as usize;
            let ki = q[2] as usize;
            let vi = q[3] as i64;
            
            let mut idx = li;
            while idx <= ri {
                arr[idx] = (arr[idx] * vi) % MOD;
                idx += ki;
            }
        }
        
        let mut result = 0;
        for &val in &arr {
            result ^= val as i32;
        }
        
        result
    }
}