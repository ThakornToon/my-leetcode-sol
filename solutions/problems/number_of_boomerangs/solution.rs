use std::collections::HashMap;
impl Solution {
    pub fn number_of_boomerangs(points: Vec<Vec<i32>>) -> i32 {
        let mut result = 0;
        for p in &points {
            let mut dist_map = HashMap::new();
            for q in &points {
                let dx = p[0] - q[0];
                let dy = p[1] - q[1];
                let dist = dx * dx + dy * dy;
                *dist_map.entry(dist).or_insert(0) += 1;
            }
            for (_, count) in dist_map {
                result += count * (count - 1);
            }
        }
        result
    }
}