impl Solution {
    pub fn intersection_size_two(intervals: Vec<Vec<i32>>) -> i32 {
        let mut intervals = intervals;
        
        // เรียง intervals ตาม end จากน้อยไปมาก
        // ถ้า end เท่ากัน ให้เรียงตาม start จากมากไปน้อย
        intervals.sort_by(|a, b| {
            if a[1] == b[1] {
                b[0].cmp(&a[0]) // start จากมากไปน้อย
            } else {
                a[1].cmp(&b[1]) // end จากน้อยไปมาก
            }
        });
        
        let mut result = 0;
        let mut last = -1;      // ตัวเลขสุดท้ายใน S
        let mut second_last = -1; // ตัวเลขรองสุดท้ายใน S
        
        for interval in intervals {
            let a = interval[0];
            let b = interval[1];
            
            if a > last {
                // Case 1: ไม่มีตัวเลขใน S ที่อยู่ใน interval นี้
                // เพิ่ม 2 ตัวเลขใหม่: b-1 และ b
                result += 2;
                last = b;
                second_last = b - 1;
            } else if a > second_last {
                // Case 2: มี 1 ตัวเลขใน S ที่อยู่ใน interval นี้
                // เพิ่ม 1 ตัวเลขใหม่: b
                result += 1;
                second_last = last;
                last = b;
            }
            // Case 3: มี ≥2 ตัวเลขใน S อยู่ใน interval นี้แล้ว → ไม่ต้องทำอะไร
        }
        
        result
    }
}