impl Solution {
    pub fn find_min_difference(time_points: Vec<String>) -> i32 {
        let mut minutes: Vec<i32> = time_points.iter()
        .map(|time| {
            let parts: Vec<&str> = time.split(':').collect();
            let hour: i32 = parts[0].parse().unwrap();
            let minute: i32 = parts[1].parse().unwrap();
            return (hour * 60) + minute;
        })
        .collect();
    
    // เรียงลำดับเวลา
    minutes.sort_unstable();
    
    let mut min_diff = i32::MAX;
    let n = minutes.len();
    
    // คำนวณความแตกต่างระหว่างเวลาที่ติดกัน
    for i in 1..n {
        min_diff = min_diff.min(minutes[i] - minutes[i-1]);
    }
    
    // ตรวจสอบความแตกต่างระหว่างเวลาสุดท้ายและเวลาต้น (การวนรอบ)
    min_diff.min(1440 + minutes[0] - minutes[n-1])
    }
}