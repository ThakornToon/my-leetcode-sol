/*
1. หาพื้นที่ตัดกันของทุกคู่สี่เหลี่ยม
สำหรับสี่เหลี่ยม i และ j:
พื้นที่ตัดกัน = [max(a_i, a_j), max(b_i, b_j), min(c_i, c_j), min(d_i, d_j)]
ถ้า max(a_i, a_j) < min(c_i, c_j) และ max(b_i, b_j) < min(d_i, d_j) → มีการตัดกัน

2. หาขนาดสี่เหลี่ยมจัตุรัสสูงสุดในพื้นที่ตัดกัน
ถ้าพื้นที่ตัดกันคือ [x1, y1, x2, y2]:
ความกว้าง = x2 - x1
ความสูง = y2 - y1
ขนาดสี่เหลี่ยมจัตุรัสสูงสุด = min(ความกว้าง, ความสูง)
พื้นที่ = (min(ความกว้าง, ความสูง))²

3. เก็บค่าสูงสุดจากทุกคู่สี่เหลี่ยม
*/

impl Solution {
    pub fn largest_square_area(bottom_left: Vec<Vec<i32>>, top_right: Vec<Vec<i32>>) -> i64 {
        let n = bottom_left.len();
        let mut max_side: i64 = 0;
        
        for i in 0..n {
            let (a1, b1) = (bottom_left[i][0], bottom_left[i][1]);
            let (c1, d1) = (top_right[i][0], top_right[i][1]);
            
            for j in (i + 1)..n {
                let (a2, b2) = (bottom_left[j][0], bottom_left[j][1]);
                let (c2, d2) = (top_right[j][0], top_right[j][1]);
                
                // คำนวณความกว้างและความสูง
                let width = c1.min(c2) - a1.max(a2);
                let height = d1.min(d2) - b1.max(b2);
                
                // ด้านของสี่เหลี่ยมจัตุรัส
                let side = width.min(height);
                
                if side > 0 {
                    max_side = max_side.max(side as i64);
                }
            }
        }
        
        max_side * max_side
    }
}