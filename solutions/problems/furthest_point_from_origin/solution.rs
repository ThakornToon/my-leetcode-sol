impl Solution {
    pub fn furthest_distance_from_origin(moves: String) -> i32 {
        let mut l: i32 = 0;
        let mut r: i32 = 0;
        let mut any: i32 = 0;
        
        for c in moves.chars() {
            match c {
                'L' => l += 1,
                'R' => r += 1,
                _ => any += 1,
            }
        }
        
        (l - r).abs() + any
    }
}