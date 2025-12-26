int dayOfYear(char* date) {
    // แยก string
    char yearStr[5], monthStr[3], dayStr[3];
    strncpy(yearStr, date, 4);
    yearStr[4] = '\0';
    strncpy(monthStr, date + 5, 2);
    monthStr[2] = '\0';
    strncpy(dayStr, date + 8, 2);
    dayStr[2] = '\0';
    
    // แปลงเป็นตัวเลข
    int year = atoi(yearStr);
    int month = atoi(monthStr);
    int day = atoi(dayStr);
    
    // จำนวนวันในแต่ละเดือน
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 
                         31, 31, 30, 31, 30, 31};
    
    // ตรวจสอบปีอธิกสุรทิน
    int isLeapYear = 0;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        isLeapYear = 1;
        daysInMonth[1] = 29;  // กุมภาพันธ์
    }
    
    // คำนวณ
    int result = 0;
    for (int i = 0; i < month - 1; i++) {
        result += daysInMonth[i];
    }
    result += day;
    
    return result;
}