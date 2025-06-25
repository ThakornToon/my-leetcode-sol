impl Solution {
    pub fn gray_code(n: i32) -> Vec<i32> {
        let mut result = vec![0];
    
        for i in 0..n {
            let add = 1 << i;
            let mut new_part: Vec<i32> = result.iter().rev().map(|&x| x + add).collect();
            result.append(&mut new_part);
        }
        
        result
    }
}