impl Solution {
    pub fn min_domino_rotations(tops: Vec<i32>, bottoms: Vec<i32>) -> i32 {
let n = tops.len();
        let mut result = i32::MAX;
        
        // ลองตัวเลือกทั้งสองที่เป็นไปได้
        result = result.min(Self::check(tops[0], &tops, &bottoms));
        result = result.min(Self::check(bottoms[0], &tops, &bottoms));
        
        if result == i32::MAX { -1 } else { result }
    }
    
    fn check(target: i32, tops: &[i32], bottoms: &[i32]) -> i32 {
        let n = tops.len();
        let mut rotations_top = 0;
        let mut rotations_bottom = 0;
        
        for i in 0..n {
            // ถ้า domino ตัวนี้ไม่มี target เลย
            if tops[i] != target && bottoms[i] != target {
                return i32::MAX;
            }
            
            // นับจำนวนการหมุนที่ต้องการ
            if tops[i] != target {
                rotations_top += 1;
            }
            if bottoms[i] != target {
                rotations_bottom += 1;
            }
        }
        
        rotations_top.min(rotations_bottom)
    }
}