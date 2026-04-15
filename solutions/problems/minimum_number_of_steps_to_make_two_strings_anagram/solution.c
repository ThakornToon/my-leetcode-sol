int minSteps(char* s, char* t) {
    int count[26] = {0};
    int len = strlen(s);
    
    // นับความถี่: s เพิ่ม, t ลด
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    
    // นับผลรวมของค่าบวก (ตัวที่ s มีเกิน)
    int steps = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            steps += count[i];
        }
    }
    
    return steps;
}