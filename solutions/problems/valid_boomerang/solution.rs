impl Solution {
    pub fn is_boomerang(points: Vec<Vec<i32>>) -> bool {
        let x1 = points[0][0];
        let y1 = points[0][1];
        let x2 = points[1][0];
        let y2 = points[1][1];
        let x3 = points[2][0];
        let y3 = points[2][1];
        
        // ตรวจสอบจุดซ้ำ
        if (x1 == x2 && y1 == y2) ||
            (x1 == x3 && y1 == y3) ||
            (x2 == x3 && y2 == y3) {
            return false;
        }
        
        // ใช้ slope โดยหลีกเลี่ยงการหาร
        // จุด collinear ถ้า: (y2-y1)/(x2-x1) = (y3-y1)/(x3-x1)
        // หรือ: (y2-y1)*(x3-x1) = (y3-y1)*(x2-x1)
        let left = (y2 - y1) * (x3 - x1);
        let right = (y3 - y1) * (x2 - x1);
        
        return left != right;
    }
}