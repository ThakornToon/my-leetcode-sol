int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int bagOfTokensScore(int* tokens, int tokensSize, int power) {
    qsort(tokens, tokensSize, sizeof(int), compare);
    
    int left = 0;
    int right = tokensSize - 1;
    int score = 0;
    int maxScore = 0;
    
    while (left <= right) {
        // พยายามเล่น face-up ก่อน (เพราะได้ score)
        if (power >= tokens[left]) {
            // ใช้ token ที่เล็กที่สุดเพื่อประหยัด power
            power -= tokens[left];
            score++;
            left++;
            
            // อัปเดต score สูงสุด
            if (score > maxScore) {
                maxScore = score;
            }
        }
        // ถ้าเล่น face-up ไม่ได้ แต่มี score และยังมี token เหลือ
        else if (score > 0 && left < right) {
            // ใช้ token ที่ใหญ่ที่สุดเพื่อได้ power เยอะสุด
            power += tokens[right];
            score--;
            right--;
        }
        // ไม่สามารถเล่นได้อีก
        else {
            break;
        }
    }
    
    return maxScore;
}