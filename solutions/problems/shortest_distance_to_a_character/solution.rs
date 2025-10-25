impl Solution {
    pub fn shortest_to_char(s: String, c: char) -> Vec<i32> {
        let n = s.len();
        let mut positions = Vec::new();
        let chars: Vec<char> = s.chars().collect();
        
        // เก็บตำแหน่งของตัวอักษร c
        for (i, &ch) in chars.iter().enumerate() {
            if ch == c {
                positions.push(i as i32);
            }
        }
        
        // คำนวณระยะทางสำหรับแต่ละตำแหน่ง
        let mut result = Vec::with_capacity(n);
        for i in 0..n {
            let mut min_dist = i32::MAX;
            for &pos in &positions {
                min_dist = min_dist.min((i as i32 - pos).abs());
            }
            result.push(min_dist);
        }
        
        result
    }
}