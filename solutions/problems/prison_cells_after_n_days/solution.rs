impl Solution {
    pub fn prison_after_n_days(cells: Vec<i32>, n: i32) -> Vec<i32> {
        // สำหรับ 8 cells cycle คือ 14 วัน
        let mut n = n % 14;
        if n == 0 {
            n = 14;
        }
        
        let mut current = cells;
        
        for _ in 0..n {
            let mut next = vec![0; 8];
            
            for i in 1..7 {
                next[i] = if current[i-1] == current[i+1] { 1 } else { 0 };
            }
            
            current = next;
        }
        
        current
    }
}