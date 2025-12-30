bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

char* dayOfTheWeek(int day, int month, int year) {
    char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", 
                   "Thursday", "Friday", "Saturday"};
    
    int monthDays[] = {31, 28, 31, 30, 31, 30, 
                       31, 31, 30, 31, 30, 31};
    
    // 1/1/1971 เป็นวันศุกร์ (index 5)
    int totalDays = 0;
    
    // จำนวนวันจากปีก่อนหน้า
    for (int y = 1971; y < year; y++) {
        totalDays += 365;
        if (isLeapYear(y)) {
            totalDays++;
        }
    }
    
    // จำนวนวันจากเดือนก่อนหน้า
    for (int m = 1; m < month; m++) {
        totalDays += monthDays[m - 1];
        if (m == 2 && isLeapYear(year)) {
            totalDays++;
        }
    }
    
    // เพิ่มวันในเดือนปัจจุบัน
    totalDays += (day - 1);
    
    // ปรับให้ 0=Sunday
    int dayIndex = (totalDays + 5) % 7;  // +5 เพราะ 1/1/1971 เป็น Friday (index 5)
    
    char* result = (char*)malloc(10 * sizeof(char));
    strcpy(result, days[dayIndex]);
    return result;
}