impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        let mut res = vec![0];
        let mut i = 0;
        let mut end = 1;
        
        while res.len() != (n + 1) as usize {
            res.push(res[i] + 1);
            i += 1;
            
            if i == end {
                end += i;
                i = 0;
            }
        }
        
        res
    }
}