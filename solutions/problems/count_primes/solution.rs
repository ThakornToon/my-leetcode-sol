impl Solution {
    pub fn count_primes(n: i32) -> i32 {
        if (n <= 1) {
            return 0;
        }
        let n = n as usize;
        let mut count = 0;
        let mut arr = vec![true; n]; //0..=(n-1)
        arr[0] = false;
        arr[1] = false;
        let sqrtn = (n as f64).sqrt() as usize;
        for i in 2..(sqrtn+1) {
            if (arr[i] == false) {
                continue;
            }
            let mut j = i * i;
            while j < n {
                arr[j] = false;
                j += i;
            }
        }
        for i in 2..n {
            if (arr[i] == true) {
                count += 1;
            }
        }
        return count;
    }
}