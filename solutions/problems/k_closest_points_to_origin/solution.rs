impl Solution {
    pub fn k_closest(points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let k = k as usize;
        let mut points = points;
        // ฟังก์ชัน partition แบบ QuickSelect
        let mut left = 0;
        let mut right = points.len() - 1;
        
        while left <= right {
            let pivot_index = Self::partition(&mut points, left, right);
            
            if pivot_index == k {
                break;
            } else if pivot_index < k {
                left = pivot_index + 1;
            } else {
                right = pivot_index - 1;
            }
        }
        
        points[..k].to_vec()
    }
    
    fn distance_sq(point: &[i32]) -> i32 {
        point[0] * point[0] + point[1] * point[1]
    }
    
    // right เป็น pivot ค่าน้อยกว่า pivot จะไปกองทางซ้าย
    fn partition(points: &mut Vec<Vec<i32>>, left: usize, right: usize) -> usize {
        let pivot_dist = Self::distance_sq(&points[right]);
        let mut i = left;
        
        for j in left..right {
            if Self::distance_sq(&points[j]) <= pivot_dist {
                points.swap(i, j);
                i += 1;
            }
        }
        
        points.swap(i, right);
        i
    }
}