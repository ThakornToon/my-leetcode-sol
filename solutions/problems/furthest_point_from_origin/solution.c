int furthestDistanceFromOrigin(char* moves) {
    int L = 0, R = 0, underscore = 0;
    int len = strlen(moves);
    
    for (int i = 0; i < len; i++) {
        if (moves[i] == 'L') L++;
        else if (moves[i] == 'R') R++;
        else underscore++;
    }
    
    // ระยะทางพื้นฐาน = |L - R|
    // underscore สามารถเพิ่มได้ทั้งหมด
    return abs(L - R) + underscore;
}