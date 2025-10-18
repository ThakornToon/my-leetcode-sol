impl Solution {
    pub fn largest_triangle_area(points: Vec<Vec<i32>>) -> f64 {
        let mut max_area: f64 = 0.0;
        let n = points.len();
        
        for i in 0..n {
            for j in i + 1..n {
                for k in j + 1..n {
                    let (x1, y1) = (points[i][0], points[i][1]);
                    let (x2, y2) = (points[j][0], points[j][1]);
                    let (x3, y3) = (points[k][0], points[k][1]);
                    
                    let area = 0.5 * ((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) as f64).abs();
                    max_area = max_area.max(area);
                }
            }
        }
        
        max_area
    }
}