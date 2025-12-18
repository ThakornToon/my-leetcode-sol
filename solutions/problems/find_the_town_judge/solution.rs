impl Solution {
    pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut given = vec![0; n + 1];   // trust given
        let mut received = vec![0; n + 1]; // trust received
        
        for t in trust {
            let a = t[0] as usize;
            let b = t[1] as usize;
            given[a] += 1;
            received[b] += 1;
        }
        
        for i in 1..=n {
            if given[i] == 0 && received[i] == n - 1 {
                return i as i32;
            }
        }
        
        -1
    }
}