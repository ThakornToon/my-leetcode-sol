int scoreOfParentheses(char* s) {
    int depth = 0;
    int score = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            depth++;
        } else {
            depth--;
            
            // ตรวจสอบว่าเป็นคู่ "()" หรือไม่
            if (s[i-1] == '(') {
                // เพิ่มคะแนน 2^depth
                score += 1 << depth;  // 2^depth
            }
        }
    }
    
    return score;
}