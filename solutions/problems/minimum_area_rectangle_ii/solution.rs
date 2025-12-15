use std::collections::HashSet;

impl Solution {
    pub fn min_area_free_rect(points: Vec<Vec<i32>>) -> f64 {
        let n = points.len();
        let point_set: HashSet<(i32, i32)> = points.iter()
            .map(|p| (p[0], p[1]))
            .collect();
        
        let mut min_area = f64::MAX;
        
        // ตรวจจากจุดสามจุด
        for i in 0..n {
            for j in i + 1..n {
                for k in j + 1..n {
                    let (x1, y1) = (points[i][0], points[i][1]);
                    let (x2, y2) = (points[j][0], points[j][1]);
                    let (x3, y3) = (points[k][0], points[k][1]);
                    
                    // ตรวจสอบ 3 กรณี (แต่ละจุดเป็นมุมฉาก)
                    Self::check_triangle((x1, y1), (x2, y2), (x3, y3), &point_set, &mut min_area);
                    Self::check_triangle((x2, y2), (x1, y1), (x3, y3), &point_set, &mut min_area);
                    Self::check_triangle((x3, y3), (x1, y1), (x2, y2), &point_set, &mut min_area);
                }
            }
        }
        
        if min_area == f64::MAX { 0.0 } else { min_area }
    }

    fn check_triangle(p1: (i32, i32), p2: (i32, i32), p3: (i32, i32), 
                     point_set: &HashSet<(i32, i32)>, min_area: &mut f64) {
        // ตรวจสอบว่า p1 เป็นมุมฉากของ p1-p2-p3
        let dx1 = p2.0 - p1.0;
        let dy1 = p2.1 - p1.1;
        let dx2 = p3.0 - p1.0;
        let dy2 = p3.1 - p1.1;
        
        if dx1 * dx2 + dy1 * dy2 == 0 {
            // คำนวณจุดที่สี่
            let p4 = (p2.0 + p3.0 - p1.0, p2.1 + p3.1 - p1.1);
            
            if point_set.contains(&p4) {
                let side1 = ((dx1 * dx1 + dy1 * dy1) as f64).sqrt();
                let side2 = ((dx2 * dx2 + dy2 * dy2) as f64).sqrt();
                let area = side1 * side2;
                
                if area > 1e-9 {
                    *min_area = (*min_area).min(area);
                }
            }
        }
    }
}