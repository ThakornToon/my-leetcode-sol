impl Solution {
    pub fn maximize_square_area(m: i32, n: i32, h_fences: Vec<i32>, v_fences: Vec<i32>) -> i32 {
        const MOD: i64 = 1_000_000_007;
        
        // รวม fences ขอบ
        let mut h_points = h_fences;
        h_points.push(1);
        h_points.push(m);
        h_points.sort_unstable();
        
        let mut v_points = v_fences;
        v_points.push(1);
        v_points.push(n);
        v_points.sort_unstable();
        
        // สร้าง HashSet สำหรับ gaps แนวนอน
        use std::collections::HashSet;
        let mut gaps = HashSet::new();
        
        // คำนวณ gaps แนวนอน
        let h_len = h_points.len();
        for i in 0..h_len {
            for j in (i + 1)..h_len {
                gaps.insert(h_points[j] - h_points[i]);
            }
        }
        
        // หา gap ที่ใหญ่ที่สุดที่เป็น common
        let mut max_side: i64 = 0;
        let v_len = v_points.len();
        
        for i in 0..v_len {
            for j in (i + 1)..v_len {
                let diff = v_points[j] - v_points[i];
                if gaps.contains(&diff) {
                    max_side = max_side.max(diff as i64);
                }
            }
        }
        
        if max_side == 0 {
            return -1;
        }
        
        let area = (max_side * max_side) % MOD;
        area as i32
    }
}