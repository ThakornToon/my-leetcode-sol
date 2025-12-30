class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        // 1/1/1971 เป็นวันศุกร์
        vector<string> days = {"Friday", "Saturday", "Sunday", "Monday", 
                              "Tuesday", "Wednesday", "Thursday"};
        
        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 
                                31, 31, 30, 31, 30, 31};
        
        // คำนวณจำนวนวันตั้งแต่ 1/1/1971
        int totalDays = 0;
        
        // จำนวนวันจากปีก่อนหน้า
        for (int y = 1971; y < year; y++) {
            totalDays += 365;
            if (isLeapYear(y)) {
                totalDays++;
            }
        }
        
        // จำนวนวันจากเดือนก่อนหน้าในปีปัจจุบัน
        for (int m = 1; m < month; m++) {
            totalDays += monthDays[m - 1];
            // ถ้าเป็นเดือนกุมภาพันธ์ในปีอธิกสุรทิน
            if (m == 2 && isLeapYear(year)) {
                totalDays++;
            }
        }
        
        // เพิ่มวันในเดือนปัจจุบัน
        totalDays += (day - 1);
        
        // คำนวณวันในสัปดาห์
        return days[totalDays % 7];
    }
    
private:
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};