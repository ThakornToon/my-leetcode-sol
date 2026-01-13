impl Solution {
    pub fn separate_squares(squares: Vec<Vec<i32>>) -> f64 {
        let mut total_area: i64 = 0; // พื้นที่ทั้งหมด
        // จะลองลากเส้นแบ่งโดยเราจะดูว่ามีสี่เหลี่ยมที่ active อยู่บนเส้นอยู่เท่าไรแล้วค่อยๆเลื่อนขึ้น
        // (ตำแหน่ง, ขนาด, 1=active)
        let mut events: Vec<(i32, i32, i32)> = Vec::new();
        
        for sq in &squares {
            let y: i32 = sq[1];
            let side: i32 = sq[2];
            total_area += side as i64 * side as i64;
            events.push((y, side, 1)); // active
            events.push((y + side, side, -1)); // พ้นเส้นไปแล้ว
        }
        
        // sort ตามตำแหน่ง y 
        events.sort_by_key(|&(y, _, _)| y);
        
        let mut covered_width: f64 = 0.0;  // sum of all bottom edges under the current scanning line
        let mut curr_area: f64 = 0.0;      // ขนาดพื้นที่ด้านล่างเส้นแบ่งทั้งหมด
        let mut prev_height: f64 = 0.0;    // ตำแหน่งเส้นที่แบ่งก่อนหน้านี้ (เริ่มที่ 0)
        
        // ลองสร้างเส้นแบ่งตามขอบสี่เหลี่ยมจากล่างขึ้นบน y น้อยไปมาก (บีบหาเส้นแบ่งที่ต้องการ)
        for (y, side, delta) in events {
            let diff = y as f64 - prev_height; // ตำแหน่งเส้นแบ่งปัจจุบันกับก่อนหน้า
            let area = covered_width * diff; // พื้นที่ระหว่างเส้นแบ่งปัจจุบันกับก่อนหน้านี้ (เพิ่มขึ้นมา)

            // ถ้าเลื่อนขึ้นแล้วได้เกินกว่าครึ่งแปลว่าเส้นแบ่งที่ต้องการอยู่ระหว่างเส้นแบ่งปัจจุบันกับก่อนหน้านี้
            if 2.0 * (curr_area + area) >= total_area as f64 {
                return prev_height + (total_area as f64 - 2.0 * curr_area) / (2.0 * covered_width);
            }

            covered_width += (delta * side) as f64; // ความยาวด้านสี่เหลี่ยมที่ active อยู่บนเส้นแบ่งอยู่ (เมื่อเลื่อนขึ้นจะมีพื้นที่เพิ่ม)
            curr_area += area; // พื้นที่ด้านล่างเส้นแบ่งปัจจุบันทั้งหมด
            prev_height = y as f64;
        }
        
        0.0
    }
}