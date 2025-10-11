impl Solution {
    pub fn min_swaps_couples(row: Vec<i32>) -> i32 {
        let mut row = row;
        let n = row.len();
        let mut position = vec![0; n];
        
        for (i, &person) in row.iter().enumerate() {
            position[person as usize] = i;
        }
        
        let mut swaps = 0;
        let mut i = 0;
        while i < n {
            let person = row[i];
            let partner = person ^ 1;
            
            if row[i + 1] != partner {
                let partner_idx = position[partner as usize];
                row.swap(i + 1, partner_idx);
                position[row[partner_idx] as usize] = partner_idx;
                position[row[i + 1] as usize] = i + 1;
                swaps += 1;
            }
            i += 2;
        }
        
        swaps
    }
}