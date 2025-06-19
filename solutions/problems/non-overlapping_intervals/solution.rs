impl Solution {
    pub fn erase_overlap_intervals(intervals: Vec<Vec<i32>>) -> i32 {
        let mut intervals = intervals;
        // เรียงลำดับช่วงเวลาตามจุดสิ้นสุด น้อยไปมาก
        intervals.sort_by(|a, b| a[1].cmp(&b[1]));
        
        let mut count = 0;
        let mut prev_end = intervals[0][1];
        
        for interval in intervals.iter().skip(1) {
            if interval[0] < prev_end {
                // มีการทับซ้อน
                count += 1;
            } else {
                // ไม่ทับซ้อน
                prev_end = interval[1];
            }
        }
        
        count
    }
}