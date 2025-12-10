impl Solution {
    pub fn three_equal_parts(arr: Vec<i32>) -> Vec<i32> {
        let n = arr.len();
        
        // รวบรวมตำแหน่งของ 1
        let ones: Vec<usize> = arr
            .iter()
            .enumerate()
            .filter(|&(_, &x)| x == 1)
            .map(|(i, _)| i)
            .collect();
        
        let m = ones.len();
        
        // กรณีไม่มี 1
        if m == 0 {
            return vec![0, (n - 1) as i32];
        }
        
        // จำนวน 1 ต้องหารด้วย 3 ลงตัว
        if m % 3 != 0 {
            return vec![-1, -1];
        }
        
        let k = m / 3;
        
        // หา trailing zeros ของส่วนที่สาม
        let trailing_zeros = n - 1 - ones[m - 1];
        
        // ส่วนแรกและส่วนที่สองต้องมี trailing zeros อย่างน้อยเท่ากับส่วนที่สาม
        if ones[k] - ones[k - 1] - 1 < trailing_zeros || 
        ones[2 * k] - ones[2 * k - 1] - 1 < trailing_zeros {
            return vec![-1, -1];
        }
        
        // คำนวณจุดแบ่ง
        let i = (ones[k - 1] + trailing_zeros);
        let j = (ones[2 * k - 1] + trailing_zeros + 1);
        
        // ตรวจสอบว่าทั้งสามส่วนเท่ากันจริงๆ
        let part1_end = i;
        let part2_start = i + 1;
        let part2_end = j - 1;
        let part3_start = j;
        
        // แปลงส่วนเป็น string สำหรับ comparison
        let part1: String = arr[0..=part1_end].iter().map(|&x| (x as u8 + b'0') as char).collect();
        let part2: String = arr[part2_start..=part2_end].iter().map(|&x| (x as u8 + b'0') as char).collect();
        let part3: String = arr[part3_start..].iter().map(|&x| (x as u8 + b'0') as char).collect();
        
        // ลบ leading zeros
        let part1_trimmed = part1.trim_start_matches('0');
        let part2_trimmed = part2.trim_start_matches('0');
        let part3_trimmed = part3.trim_start_matches('0');
        
        // ตรวจสอบว่าเท่ากัน
        if part1_trimmed == part2_trimmed && part2_trimmed == part3_trimmed {
            vec![i as i32, j as i32]
        } else {
            vec![-1, -1]
        }
    }
}