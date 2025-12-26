class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        // จำนวนวันในแต่ละเดือน (ไม่ใช่ปีอธิกสุรทิน)
        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 
                               31, 31, 30, 31, 30, 31};
        
        // ตรวจสอบปีอธิกสุรทิน
        bool isLeapYear = false;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            isLeapYear = true;
            daysInMonth[1] = 29;  // กุมภาพันธ์มี 29 วัน
        }
        
        // คำนวณผลรวม
        int dayOfYear = 0;
        for (int i = 0; i < month - 1; i++) {
            dayOfYear += daysInMonth[i];
        }
        dayOfYear += day;
        
        return dayOfYear;
    }
};