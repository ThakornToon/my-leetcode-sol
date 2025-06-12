impl Solution {
    pub fn nth_super_ugly_number(n: i32, primes: Vec<i32>) -> i32 {
        let mut factor = vec![0; primes.len()];
        let n = n as usize;
        let mut k: Vec<i32> = vec![1; n];
        for i in 1..n {
            let mut next = i32::MAX;
            for j in 0..primes.len() {
                next = next.min(k[factor[j]].saturating_mul(primes[j]));
            }
            k[i] = next;
            for j in 0..primes.len() {
                if (k[i] == k[factor[j]].saturating_mul(primes[j])) {
                    factor[j] += 1;
                }
            }
        }
        return k[n-1];
    }
}