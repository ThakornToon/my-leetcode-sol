use std::collections::VecDeque;
use std::cmp::min;

impl Solution {
    pub fn minimum_distance(word: String) -> i32 {
        let word = word.as_bytes();
        let n = word.len();
        
        // ฟังก์ชันคำนวณระยะทาง
        fn dist(from: u8, to: u8) -> i32 {
            let from = from as i32;
            let to = to as i32;
            let x1 = from / 6;
            let y1 = from % 6;
            let x2 = to / 6;
            let y2 = to % 6;
            (x1 - x2).abs() + (y1 - y2).abs()
        }
        
        // แปลงตัวอักษรเป็นตำแหน่ง (0-25)
        let positions: Vec<u8> = word.iter().map(|&c| c - b'A').collect();
        
        // visited[position_index][finger1][finger2] = minimum distance
        // ใช้ 3D array ขนาด n x 26 x 26
        let mut visited = vec![vec![vec![i32::MAX; 26]; 26]; n];
        
        // Queue: (index, finger1_pos, finger2_pos)
        let mut queue = VecDeque::new();
        
        // เริ่มต้นที่ index 0 ด้วยนิ้วทั้งสองที่ตำแหน่งใดก็ได้
        // เราใช้ 26 แทนการไม่ใช้นิ้ว
        let first_pos = positions[0] as usize;
        
        // กรณี: ใช้นิ้ว 1 พิมพ์ตัวแรก
        for f2 in 0..26 {
            if visited[0][first_pos][f2] > 0 {
                visited[0][first_pos][f2] = 0;
                queue.push_back((0, first_pos, f2));
            }
        }
        
        // กรณี: ใช้นิ้ว 2 พิมพ์ตัวแรก
        for f1 in 0..26 {
            if visited[0][f1][first_pos] > 0 {
                visited[0][f1][first_pos] = 0;
                queue.push_back((0, f1, first_pos));
            }
        }
        
        // BFS
        while let Some((idx, f1, f2)) = queue.pop_front() {
            let current_dist = visited[idx][f1][f2];
            
            // ถ้าพิมพ์ครบแล้ว
            if idx == n - 1 {
                continue;
            }
            
            let next_pos = positions[idx + 1] as usize;
            
            // ลองใช้นิ้ว 1 พิมพ์ตัวถัดไป
            if visited[idx + 1][next_pos][f2] > current_dist + dist(f1 as u8, next_pos as u8) {
                let new_dist = current_dist + dist(f1 as u8, next_pos as u8);
                visited[idx + 1][next_pos][f2] = new_dist;
                queue.push_back((idx + 1, next_pos, f2));
            }
            
            // ลองใช้นิ้ว 2 พิมพ์ตัวถัดไป
            if visited[idx + 1][f1][next_pos] > current_dist + dist(f2 as u8, next_pos as u8) {
                let new_dist = current_dist + dist(f2 as u8, next_pos as u8);
                visited[idx + 1][f1][next_pos] = new_dist;
                queue.push_back((idx + 1, f1, next_pos));
            }
        }
        
        // หาค่าน้อยที่สุดหลังจากพิมพ์ครบทุกตัว
        let mut result = i32::MAX;
        for f1 in 0..26 {
            for f2 in 0..26 {
                result = min(result, visited[n - 1][f1][f2]);
            }
        }
        
        result
    }
}