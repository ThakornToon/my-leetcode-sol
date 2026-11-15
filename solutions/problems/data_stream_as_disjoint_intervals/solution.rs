/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */

struct SummaryRanges {
    intervals: Vec<Vec<i32>>,
}

impl SummaryRanges {

    fn new() -> Self {
        SummaryRanges {
            intervals: Vec::new(),
        }
    }
    
    fn add_num(&mut self, val: i32) {
        // ใช้ binary search หาตำแหน่งแรกที่ interval[0] > val
        let idx = self.intervals.partition_point(|interval| interval[0] <= val);
        
        // ถ้าค่านั้นอยู่ในช่วงเดิมอยู่แล้ว ไม่ต้องทำอะไร
        if idx > 0 && val <= self.intervals[idx - 1][1] {
            return;
        }
        
        let touch_left: bool = idx > 0 && self.intervals[idx - 1][1] == val - 1;
        let touch_right: bool = idx < self.intervals.len() && self.intervals[idx][0] == val + 1;
        
        match (touch_left, touch_right) {
            (true, true) => {
                // ชนทั้งสองฝั่ง: ขยายช่วงซ้ายให้กินช่วงขวา แล้วลบช่วงขวาทิ้ง 1 ตัว
                let right_end = self.intervals[idx][1];
                let left_interval = &mut self.intervals[idx - 1];
                left_interval[1] = left_interval[1].max(right_end);
                self.intervals.remove(idx);
            }
            (true, false) => {
                // ชนแค่ซ้าย: ขยายขอบเขตขวาของช่วงซ้าย
                let left_interval = &mut self.intervals[idx - 1];
                left_interval[1] = left_interval[1].max(val);
            }
            (false, true) => {
                // ชนแค่ขวา: ขยายขอบเขตซ้ายของช่วงขวา
                let right_interval = &mut self.intervals[idx][0];
                *right_interval = (*right_interval).min(val);
            }
            (false, false) => {
                // ไม่ชนใครเลย: สร้างช่วงใหม่ [val, val] แทรกเข้าไป
                self.intervals.insert(idx, vec![val, val]);
            }
        }
    }
    
    fn get_intervals(&self) -> Vec<Vec<i32>> {
        self.intervals.clone()
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * let obj = SummaryRanges::new();
 * obj.add_num(value);
 * let ret_2: Vec<Vec<i32>> = obj.get_intervals();
 */