bool checkStrings(char* s1, char* s2) {
    int n = strlen(s1);
    
    // ใช้ array ขนาด 26 แทน HashMap (เพราะมีแค่ a-z)
    int even_count_s1[26] = {0};
    int even_count_s2[26] = {0};
    int odd_count_s1[26] = {0};
    int odd_count_s2[26] = {0};
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            even_count_s1[s1[i] - 'a']++;
            even_count_s2[s2[i] - 'a']++;
        } else {
            odd_count_s1[s1[i] - 'a']++;
            odd_count_s2[s2[i] - 'a']++;
        }
    }
    
    // เปรียบเทียบ
    for (int i = 0; i < 26; i++) {
        if (even_count_s1[i] != even_count_s2[i] || 
            odd_count_s1[i] != odd_count_s2[i]) {
            return false;
        }
    }
    
    return true;
}