impl Solution {
    pub fn max_distance(colors: Vec<i32>) -> i32 {
        let n = colors.len();
        let mut max_dist = 0;
        
        // ตรวจสอบจากซ้าย
        for i in 0..n {
            if colors[i] != colors[n - 1] {
                max_dist = max_dist.max(n - 1 - i);
                break;
            }
        }
        
        // ตรวจสอบจากขวา
        for i in (0..n).rev() {
            if colors[i] != colors[0] {
                max_dist = max_dist.max(i);
                break;
            }
        }
        
        max_dist as i32
    }
}