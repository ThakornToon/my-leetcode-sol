impl Solution {
    const MOD: i64 = 1_000_000_007;

    pub fn number_of_arrays(s: String, k: i32) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let k = k as i64;
        let mut memo = vec![-1; n];
        
        fn dfs(pos: usize, s: &[u8], k: i64, memo: &mut Vec<i64>) -> i64 {
            if pos == s.len() { return 1; }  // end dfs
            if s[pos] == b'0' { return 0; }  // leading zero
            if memo[pos] != -1 { return memo[pos]; }  // already think
            
            let mut num = 0;
            let mut res = 0;
            
            // cut at pos to i
            for i in pos..s.len() {
                num = num * 10 + (s[i] - b'0') as i64;
                if num > k { break; }
                res = (res + dfs(i + 1, s, k, memo)) % Solution::MOD;
            }

            // every possible way start at pos
            memo[pos] = res;
            res
        }
        
        dfs(0, s, k, &mut memo) as i32
    }
}