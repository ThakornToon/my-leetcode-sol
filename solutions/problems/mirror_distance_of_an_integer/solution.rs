impl Solution {
    pub fn mirror_distance(n: i32) -> i32 {
        let s = n.to_string();
        let rev: String = s.chars().rev().collect();
        let reversed: i32 = rev.parse().unwrap();
        (n - reversed).abs()
    }
}