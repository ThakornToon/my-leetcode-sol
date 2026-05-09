char* reformatDate(char* date) {
    char* result = (char*)malloc(11 * sizeof(char));
    
    // แยก day, month, year
    char day[5], month[4], year[5];
    sscanf(date, "%s %s %s", day, month, year);
    
    // ตัด suffix ออกจาก day
    int d;
    sscanf(day, "%d", &d);
    
    // แปลง month name เป็นตัวเลข
    char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int m = 0;
    for (int i = 0; i < 12; i++) {
        if (strcmp(month, months[i]) == 0) {
            m = i + 1;
            break;
        }
    }
    
    // format result
    sprintf(result, "%s-%02d-%02d", year, m, d);
    
    return result;
}