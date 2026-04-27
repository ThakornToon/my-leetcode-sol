impl Solution {
    pub fn find_diagonal_order(nums: Vec<Vec<i32>>) -> Vec<i32> {
        let mut elements: Vec<(usize, usize, i32)> = Vec::new();
        
        for i in 0..nums.len() {
            for j in 0..nums[i].len() {
                elements.push((i + j, i, nums[i][j]));
            }
        }
        
        elements.sort_by(|a, b| {
            if a.0 != b.0 {
                a.0.cmp(&b.0)
            } else {
                b.1.cmp(&a.1)
            }
        });
        
        elements.into_iter().map(|(_, _, val)| val).collect()
    }
}