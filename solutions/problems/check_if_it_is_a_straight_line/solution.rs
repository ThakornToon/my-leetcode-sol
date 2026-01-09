impl Solution {
    pub fn check_straight_line(coordinates: Vec<Vec<i32>>) -> bool {
        let n = coordinates.len();
        // ดึงพิกัดของจุดแรกและจุดที่สอง
        let x0 = coordinates[0][0];
        let y0 = coordinates[0][1];
        let x1 = coordinates[1][0];
        let y1 = coordinates[1][1];
        
        // คำนวณความแตกต่าง
        let dx = x1 - x0;
        let dy = y1 - y0;
        
        // ตรวจสอบทุกจุดที่เหลือ
        for i in 2..n {
            let xi = coordinates[i][0];
            let yi = coordinates[i][1];
            
            // ใช้สูตร cross multiplication:
            // (yi - y0) * dx == (xi - x0) * dy
            if (yi - y0) * dx != (xi - x0) * dy {
                return false;
            }
        }
        
        true
    }
}