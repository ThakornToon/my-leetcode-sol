int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findMinDifference(char** timePoints, int timePointsSize) {
    int* minutes = (int*)malloc(timePointsSize * sizeof(int));
    
    // แปลงเวลาทั้งหมดเป็นนาทีเริ่มที่ 00:00
    for (int i = 0; i < timePointsSize; i++) {
        char hourStr[3] = {timePoints[i][0], timePoints[i][1], '\0'};
        char minStr[3] = {timePoints[i][3], timePoints[i][4], '\0'};
        int hour = atoi(hourStr);
        int minute = atoi(minStr);
        minutes[i] = (hour * 60) + minute;
    }
    
    // เรียงลำดับเวลา
    qsort(minutes, timePointsSize, sizeof(int), compare);
    
    int minDiff = INT_MAX;
    
    // คำนวณความแตกต่างระหว่างเวลาที่ติดกัน
    for (int i = 1; i < timePointsSize; i++) {
        int diff = minutes[i] - minutes[i-1];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    
    // ตรวจสอบความแตกต่างระหว่างเวลาสุดท้ายและเวลาต้น (การวนรอบ) 
    int circularDiff = 1440 + minutes[0] - minutes[timePointsSize - 1];
    if (circularDiff < minDiff) {
        minDiff = circularDiff;
    }
    
    free(minutes);
    return minDiff;
}