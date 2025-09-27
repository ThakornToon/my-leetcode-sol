impl Solution {
    pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
        let mut flowerbed = flowerbed;
        let mut count = 0;
        let size = flowerbed.len();
        
        for i in 0..size {
            if flowerbed[i] == 0 {
                // ตรวจสอบตำแหน่งก่อนหน้าและถัดไป
                let empty_prev = i == 0 || flowerbed[i-1] == 0;
                let empty_next = i == size-1 || flowerbed[i+1] == 0;
                
                if empty_prev && empty_next {
                    flowerbed[i] = 1;
                    count += 1;
                    
                    if count >= n {
                        return true;
                    }
                }
            }
        }
        
        count >= n
    }
}