impl Solution {
    pub fn largest_overlap(img1: Vec<Vec<i32>>, img2: Vec<Vec<i32>>) -> i32 {
        let n = img1.len();
        let mut ones1 = Vec::new();
        let mut ones2 = Vec::new();
        
        // เก็บตำแหน่งที่เป็น 1
        for i in 0..n {
            for j in 0..n {
                if img1[i][j] == 1 {
                    ones1.push((i, j));
                }
                if img2[i][j] == 1 {
                    ones2.push((i, j));
                }
            }
        }
        
        let mut shift_count = std::collections::HashMap::new();
        let mut max_overlap = 0;
        
        for &(r1, c1) in &ones1 {
            for &(r2, c2) in &ones2 {
                let dr = r2 as i32 - r1 as i32;
                let dc = c2 as i32 - c1 as i32;
                
                let count = shift_count.entry((dr, dc)).or_insert(0);
                *count += 1;
                max_overlap = max_overlap.max(*count);
            }
        }
        
        max_overlap
    }
}