impl Solution {
    pub fn maximize_square_hole_area(n: i32, m: i32, h_bars: Vec<i32>, v_bars: Vec<i32>) -> i32 {
        // หา max consecutive bars สำหรับ horizontal
        let max_h = Self::max_consecutive_bars(&h_bars);
        
        // หา max consecutive bars สำหรับ vertical
        let max_v = Self::max_consecutive_bars(&v_bars);
        
        // side length = min(max_h, max_v) + 1
        let side = max_h.min(max_v) + 1;
        side * side
    }
    
    fn max_consecutive_bars(bars: &[i32]) -> i32 {
        if bars.is_empty() {
            return 0;
        }
        
        let mut sorted_bars = bars.to_vec();
        sorted_bars.sort();
        
        let mut max_count = 1;
        let mut current = 1;
        
        for i in 1..sorted_bars.len() {
            if sorted_bars[i] == sorted_bars[i-1] + 1 {
                current += 1;
                max_count = max_count.max(current);
            } else {
                current = 1;
            }
        }
        
        // ตรวจสอบกรณีสุดท้าย
        max_count.max(current)
    }
}