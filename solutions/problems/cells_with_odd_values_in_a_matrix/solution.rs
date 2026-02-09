impl Solution {
    pub fn odd_cells(m: i32, n: i32, indices: Vec<Vec<i32>>) -> i32 {
        let m = m as usize;
        let n = n as usize;
        
        let mut rows = vec![0; m];
        let mut cols = vec![0; n];
        
        for idx in indices {
            let ri = idx[0] as usize;
            let ci = idx[1] as usize;
            
            rows[ri] ^= 1;  // Flip parity
            cols[ci] ^= 1;  // Flip parity
        }
        
        let row_odds = rows.iter().filter(|&&x| x == 1).count() as i32;
        let col_odds = cols.iter().filter(|&&x| x == 1).count() as i32;
        
        row_odds * (n as i32 - col_odds) + (m as i32 - row_odds) * col_odds
    }
}