impl Solution {
    pub fn remove_covered_intervals(intervals: Vec<Vec<i32>>) -> i32 {
        let mut intervals = intervals;
        
        // เรียงตาม l จากน้อยไปมาก, ถ้า l เท่ากันให้เรียง r จากมากไปน้อย
        intervals.sort_by(|a, b| {
            if a[0] != b[0] {
                a[0].cmp(&b[0])
            } else {
                b[1].cmp(&a[1])
            }
        });
        
        let mut count = 1;
        let mut max_right = intervals[0][1];
        
        for i in 1..intervals.len() {
            if intervals[i][1] > max_right {
                count += 1;
                max_right = intervals[i][1];
            }
        }
        
        count
    }
}