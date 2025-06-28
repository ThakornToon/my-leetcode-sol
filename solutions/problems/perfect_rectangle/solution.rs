impl Solution {
    // ในสี่เหลี่ยมที่ประกอบกันสมบูรณ์แบบ ทุกมุมภายใน (ที่ไม่ใช่มุมของสี่เหลี่ยมใหญ่สุด) ต้องปรากฏ 2 หรือ 4 ครั้ง (คู่กับสี่เหลี่ยมข้างเคียง) มุมของสี่เหลี่ยมใหญ่สุด ต้องปรากฏ เพียง 1 ครั้ง
    pub fn is_rectangle_cover(rectangles: Vec<Vec<i32>>) -> bool {
        use std::collections::HashSet;
        let (mut x1, mut y1, mut x2, mut y2) = (i32::MAX, i32::MAX, i32::MIN, i32::MIN);
        let mut area = 0;
        let mut corners = HashSet::new();

        for rect in &rectangles {
            let (rx1, ry1, rx2, ry2) = (rect[0], rect[1], rect[2], rect[3]);
            
            // อัปเดตขอบเขตสี่เหลี่ยมใหญ่
            x1 = x1.min(rx1);
            y1 = y1.min(ry1);
            x2 = x2.max(rx2);
            y2 = y2.max(ry2);
            
            // คำนวณพื้นที่รวม
            area += (rx2 - rx1) as i64 * (ry2 - ry1) as i64;
            
            // ตรวจสอบมุมที่ซ้อนทับ
            let rect_corners = [(rx1, ry1), (rx1, ry2), (rx2, ry1), (rx2, ry2)];
            for &(x, y) in &rect_corners {
                if !corners.insert((x, y)) {
                    // ทำงานเมื่อค่า corner มีอยู่ในเซตมาก่อนแล้ว
                    corners.remove(&(x, y));
                }
            }
        }
        
        // ตรวจสอบพื้นที่
        let total_area = (x2 - x1) as i64 * (y2 - y1) as i64;
        if area != total_area {
            return false;
        }
        
        // ตรวจสอบมุมของสี่เหลี่ยมใหญ่
        let outer_corners = [(x1, y1), (x1, y2), (x2, y1), (x2, y2)];
        for &corner in &outer_corners {
            if !corners.contains(&corner) { 
                // มุมของสี่เหลี่ยมใหญ่ต้องปรากฏในเซตของมุม
                return false;
            }
        }
        
        // ต้องมีมุมเหลือแค่ 4 มุมเท่านั้น (มุมของสี่เหลี่ยมใหญ่)
        corners.len() == 4
    }
}