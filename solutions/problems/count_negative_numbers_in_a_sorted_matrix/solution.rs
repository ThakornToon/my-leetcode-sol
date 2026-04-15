impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
        grid.iter()
            .flat_map(|row| row.iter())
            .filter(|&x| *x < 0)
            .count() as i32
    }
}