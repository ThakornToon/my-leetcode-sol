int max(int a, int b) {
    return a > b ? a : b;
}

int maxScoreSightseeingPair(int* values, int valuesSize) {
    if (valuesSize < 2) return 0;
    
    int max_left = values[0] + 0;  // values[i] + i
    int max_score = INT_MIN;
    
    for (int j = 1; j < valuesSize; j++) {
        // คำนวณ score สำหรับ j ปัจจุบัน
        int current_score = max_left + values[j] - j;
        max_score = max(max_score, current_score);
        
        // อัปเดต max_left สำหรับ j ถัดไป
        max_left = max(max_left, values[j] + j);
    }
    
    return max_score;
}