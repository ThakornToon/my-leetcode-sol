impl Solution {
    pub fn num_of_ways(n: i32) -> i32 {
        let n = n as usize;
        let modulo = 1_000_000_007;
        
        let mut aba = 6u64;  // Type ABA
        let mut abc = 6u64;  // Type ABC
        
        for _ in 1..n {
            let new_aba = (3 * aba + 2 * abc) % modulo;
            let new_abc = (2 * aba + 2 * abc) % modulo;
            aba = new_aba;
            abc = new_abc;
        }
        
        ((aba + abc) % modulo) as i32
    }
}