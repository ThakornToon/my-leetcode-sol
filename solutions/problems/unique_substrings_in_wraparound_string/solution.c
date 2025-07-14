int findSubstringInWraproundString(char* s) {
    int max_len[26] = {0}; // เก็บความยาวสูงสุดที่ลงท้ายด้วยแต่ละตัวอักษร
    int current_max = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (i > 0 && (s[i] - s[i-1] == 1 || s[i-1] - s[i] == 25)) {
            current_max++;
        } else {
            current_max = 1;
        }
        
        if (current_max > max_len[s[i] - 'a']) {
            max_len[s[i] - 'a'] = current_max;
        }
    }

    int total = 0;
    for (int i = 0; i < 26; i++) {
        total += max_len[i]; // sub string ที่เป็นไปได้เมื่อลงท้ายด้วยตัวอักษรนั้นๆ
    }
    
    return total;
}
