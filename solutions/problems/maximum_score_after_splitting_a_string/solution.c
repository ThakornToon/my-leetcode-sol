int maxScore(char* s) {
    int n = strlen(s);
    
    // คำนวณจำนวน '1' ทั้งหมด
    int totalOnes = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') totalOnes++;
    }
    
    int zerosLeft = 0;
    int onesLeft = 0;
    int maxScore = 0;
    
    // split ที่ตำแหน่ง i (left = s[0..i], right = s[i+1..n-1])
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0') {
            zerosLeft++;
        } else {
            onesLeft++;
        }
        
        int score = zerosLeft + (totalOnes - onesLeft);
        if (score > maxScore) {
            maxScore = score;
        }
    }
    
    return maxScore;
}