bool checkRecord(char* s) {
    int absentCount = 0;
    int lateStreak = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'A') {
            absentCount++;
            lateStreak = 0;
            if (absentCount >= 2) {
                return false;
            }
        } else if (s[i] == 'L') {
            lateStreak++;
            if (lateStreak >= 3) {
                return false;
            }
        } else {
            lateStreak = 0;
        }
    }
    
    return true;
}