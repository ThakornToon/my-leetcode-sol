impl Solution {
    pub fn max_dist_to_closest(seats: Vec<i32>) -> i32 {
        let n = seats.len();
        let mut max_dist = 0;
        let mut last_person: Option<usize> = None;
        
        for (i, &seat) in seats.iter().enumerate() {
            if seat == 1 {
                if let Some(last) = last_person {
                    // ระยะทางตรงกลาง gap
                    let dist = (i - last) / 2;
                    max_dist = max_dist.max(dist);
                } else {
                    // gap ทางซ้ายสุด
                    max_dist = max_dist.max(i);
                }
                last_person = Some(i);
            }
        }
        
        // gap ทางขวาสุด
        if let Some(last) = last_person {
            let dist = n - 1 - last;
            max_dist = max_dist.max(dist);
        }
        
        max_dist as i32
    }
}