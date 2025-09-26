impl Solution {
    pub fn valid_square(p1: Vec<i32>, p2: Vec<i32>, p3: Vec<i32>, p4: Vec<i32>) -> bool {
        let points = vec![p1, p2, p3, p4];
        let mut dists = Vec::new();
        
        // คำนวณระยะทางทั้งหมด 6 ระยะ
        for i in 0..4 {
            for j in (i + 1)..4 {
                let dist = Self::calculate_distance(&points[i], &points[j]);
                if dist == 0 {
                    return false; // จุดซ้ำ
                }
                dists.push(dist);
            }
        }
        
        // เรียงลำดับระยะทาง
        dists.sort();
        
        // ตรวจสอบคุณสมบัติของสี่เหลี่ยมจัตุรัส
        dists[0] == dists[1] && 
        dists[1] == dists[2] && 
        dists[2] == dists[3] && 
        dists[4] == dists[5] && 
        dists[0] * 2 == dists[4]
    }
    
    fn calculate_distance(p1: &[i32], p2: &[i32]) -> i32 {
        let dx = p1[0] - p2[0];
        let dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }
}