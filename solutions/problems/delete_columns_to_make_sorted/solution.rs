impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let rows = strs.len();
        let cols = strs[0].len();
        let mut count = 0;
        
        for col in 0..cols {
            let mut sorted = true;
            let mut prev = strs[0].as_bytes()[col];
            
            for row in 1..rows {
                let current = strs[row].as_bytes()[col];
                if current < prev {
                    sorted = false;
                    break;
                }
                prev = current;
            }
            
            if !sorted {
                count += 1;
            }
        }
        
        count
    }
}