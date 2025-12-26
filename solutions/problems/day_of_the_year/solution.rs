impl Solution {
    pub fn day_of_year(date: String) -> i32 {
        // แยกส่วนของวันที่
        let parts: Vec<&str> = date.split('-').collect();
        let year: i32 = parts[0].parse().unwrap();
        let month: i32 = parts[1].parse().unwrap();
        let day: i32 = parts[2].parse().unwrap();
        
        // จำนวนวันในแต่ละเดือน
        let mut days_in_month = [31, 28, 31, 30, 31, 30, 
                                 31, 31, 30, 31, 30, 31];
        
        // ตรวจสอบปีอธิกสุรทิน
        let is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if is_leap_year {
            days_in_month[1] = 29;  // กุมภาพันธ์
        }
        
        // คำนวณ
        let mut result = 0;
        for i in 0..(month - 1) as usize {
            result += days_in_month[i];
        }
        result += day;
        
        result
    }
}