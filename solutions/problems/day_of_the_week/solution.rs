impl Solution {
    pub fn day_of_the_week(day: i32, month: i32, year: i32) -> String {
let days = ["Sunday", "Monday", "Tuesday", "Wednesday", 
                   "Thursday", "Friday", "Saturday"];
        
        let month_days = [31, 28, 31, 30, 31, 30, 
                          31, 31, 30, 31, 30, 31];
        
        // 1/1/1971 เป็นวันศุกร์
        let mut total_days = 0;
        
        // ปีก่อนหน้า
        for y in 1971..year {
            total_days += 365;
            if Self::is_leap_year(y) {
                total_days += 1;
            }
        }
        
        // เดือนก่อนหน้า
        for m in 1..month {
            total_days += month_days[(m - 1) as usize];
            if m == 2 && Self::is_leap_year(year) {
                total_days += 1;
            }
        }
        
        // วันในเดือนปัจจุบัน
        total_days += day - 1;
        
        // คำนวณวันในสัปดาห์ (ปรับให้ 0=Sunday)
        let day_index = (total_days as usize + 5) % 7;  // +5 เพราะ 1/1/1971 เป็น Friday
        
        days[day_index].to_string()
    }
    
    fn is_leap_year(year: i32) -> bool {
        (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)
    }
}