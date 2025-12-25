int longestWPI(int* hours, int hoursSize) {
    int maxLen = 0;
    
    for (int i = 0; i < hoursSize; i++) {
        int score = 0;
        for (int j = i; j < hoursSize; j++) {
            score += (hours[j] > 8) ? 1 : -1;
            
            if (score > 0 && (j - i + 1) > maxLen) {
                maxLen = j - i + 1;
            }
        }
    }
    
    return maxLen;
}