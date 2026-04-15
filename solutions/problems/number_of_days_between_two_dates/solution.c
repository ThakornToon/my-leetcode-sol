// ตรวจสอบปีอธิกสุรทิน
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// จำนวนวันในแต่ละเดือน (ปกติ)
int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// นับจำนวนวันตั้งแต่วันที่ 1971-01-01 ถึงวันที่กำหนด
int daysSinceEpoch(int year, int month, int day) {
    int days = 0;
    
    // นับวันของปีที่ผ่านมา
    for (int y = 1971; y < year; y++) {
        days += isLeapYear(y) ? 366 : 365;
    }
    
    // นับวันในปีปัจจุบัน (เดือนที่ผ่านมา)
    for (int m = 1; m < month; m++) {
        days += daysInMonth[m - 1];
        if (m == 2 && isLeapYear(year)) {
            days += 1;  // กุมภาพันธ์มี 29 วันในปีอธิกสุรทิน
        }
    }
    
    // บวกวันในเดือนปัจจุบัน
    days += day;
    
    return days;
}

int daysBetweenDates(char* date1, char* date2) {
    // แยกปี เดือน วัน
    int y1, m1, d1, y2, m2, d2;
    sscanf(date1, "%d-%d-%d", &y1, &m1, &d1);
    sscanf(date2, "%d-%d-%d", &y2, &m2, &d2);
    
    int days1 = daysSinceEpoch(y1, m1, d1);
    int days2 = daysSinceEpoch(y2, m2, d2);
    
    return abs(days1 - days2);
}