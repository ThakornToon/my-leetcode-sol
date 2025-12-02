impl Solution {
    pub fn car_fleet(target: i32, position: Vec<i32>, speed: Vec<i32>) -> i32 {
        let n = position.len();
        if n == 0 {
            return 0;
        }
        
        // สร้าง vector ของ (position, time)
        let mut cars: Vec<(i32, f64)> = position
            .iter()
            .zip(speed.iter())
            .map(|(&pos, &spd)| {
                let time = (target - pos) as f64 / spd as f64;
                (pos, time)
            })
            .collect();
        
        // เรียงจาก position สูงไปต่ำ
        cars.sort_by(|a, b| b.0.cmp(&a.0));
        
        let mut fleets = 0;
        let mut current_max_time = 0.0;
        
        for (_, time) in cars {
            if time > current_max_time {
                fleets += 1;
                current_max_time = time;
            }
            // ถ้า time <= current_max_time → รวม fleet เดียวกัน
        }
        
        fleets
    }
}