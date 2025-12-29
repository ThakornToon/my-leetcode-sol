impl Solution {
    pub fn num_prime_arrangements(n: i32) -> i32 {
        let mod_val = 1_000_000_007;
        let n = n as usize;
        
        // นับจำนวนเฉพาะ
        let prime_count = Self::count_primes(n);
        let non_prime_count = n - prime_count;
        
        // คำนวณ factorial
        let prime_fact = Self::factorial(prime_count, mod_val);
        let non_prime_fact = Self::factorial(non_prime_count, mod_val);
        
        ((prime_fact * non_prime_fact) % mod_val) as i32
    }
    
    fn count_primes(n: usize) -> usize {
        let mut is_prime = vec![true; n + 1];
        is_prime[0] = false;
        is_prime[1] = false;
        
        // Sieve of Eratosthenes
        let sqrt_n = (n as f64).sqrt() as usize;
        for i in 2..=sqrt_n {
            if is_prime[i] {
                let mut j = i * i;
                while j <= n {
                    is_prime[j] = false;
                    j += i;
                }
            }
        }
        
        // นับ
        is_prime.iter().filter(|&&x| x).count()
    }
    
    fn factorial(n: usize, mod_val: i64) -> i64 {
        let mut result = 1;
        for i in 2..=n {
            result = (result * (i as i64)) % mod_val;
        }
        result
    }
}
