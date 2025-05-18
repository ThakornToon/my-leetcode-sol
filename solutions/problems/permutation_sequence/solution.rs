impl Solution {
    pub fn fac(n: i32) -> i32 {
        let mut fac = 1;
        for i in 2..=n {
            fac*=i;
        }
        return fac;
    }
    pub fn get_permutation(n: i32, k: i32) -> String {
        let mut s = String::from("");
        let mut v: Vec<i32> = (1..=n).collect();
        let mut k = k;
        let mut n = n;
        while k >=  0 && n > 0 {
            let i = Self::fac(n-1);
            let mut num_idx = k/i;
            if k%i == 0 {
                num_idx-=1;
            }
            k = k - i * num_idx;
            if let Some(c) = char::from_u32(v[num_idx as usize] as u32 + '0' as u32) {
                v.remove(num_idx as usize);
                s.push(c);
                n-=1;
            }
        }

        return s;
    }
}