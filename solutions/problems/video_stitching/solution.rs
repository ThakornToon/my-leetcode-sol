impl Solution {
    pub fn video_stitching(clips: Vec<Vec<i32>>, time: i32) -> i32 {
        let time = time as usize;
        let mut max_end = vec![0; time + 1];
        
        // เก็บ max_end สำหรับแต่ละ start
        for clip in clips {
            let start = clip[0] as usize;
            let end = clip[1] as usize;
            
            if start <= time {
                max_end[start] = max_end[start].max(end);
            }
        }
        
        let mut current_end = 0;
        let mut next_end = 0;
        let mut count = 0;
        
        for i in 0..=time {
            // อัปเดต next_end
            if max_end[i] > next_end {
                next_end = max_end[i];
            }
            
            // ถึงจุดที่ต้องเลือกคลิปใหม่
            if i == current_end {
                if next_end <= current_end {
                    return -1;
                }
                
                count += 1;
                current_end = next_end;
                
                if current_end >= time {
                    break;
                }
            }
        }
        
        if current_end >= time {
            count
        } else {
            -1
        }
    }
}