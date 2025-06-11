impl Solution {
    pub fn nth_ugly_number(n: i32) -> i32 {
        let (mut t2, mut t3, mut t5) = (0, 0, 0);
        let n = n as usize;
        let mut k = vec![1; n];
        for i in 1..n {
            k[i] = (k[t2] * 2 ).min( (k[t3] * 3).min(k[t5] * 5) );
            if (k[i] == k[t2] * 2) {
                t2 += 1; 
            }
            if (k[i] == k[t3] * 3) {
                t3 += 1;
            }
            if (k[i] == k[t5]*5) {
                t5 += 1;
            } 
        }
        return k[n-1];
    }
}