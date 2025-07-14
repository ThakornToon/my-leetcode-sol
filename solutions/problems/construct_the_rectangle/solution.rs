impl Solution {
    pub fn construct_rectangle(area: i32) -> Vec<i32> {
        let mut width = (area as f64).sqrt() as i32;
        while area % width != 0 {
            width -= 1;
        }
        vec![area / width, width]
    }
}