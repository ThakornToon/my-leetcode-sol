bool checkIfCanBreak(char* s1, char* s2) {
    int count1[26] = {0};
    int count2[26] = {0};
    int n = strlen(s1);
    
    for (int i = 0; i < n; i++) {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }
    
    // prefix sum
    int prefix1 = 0, prefix2 = 0;
    bool s1LeS2 = true, s1GeS2 = true;
    
    for (int i = 0; i < 26; i++) {
        prefix1 += count1[i];
        prefix2 += count2[i];
        
        if (prefix1 > prefix2) s1LeS2 = false;  // s1[i] <= s2[i]
        if (prefix2 > prefix1) s1GeS2 = false;  // s1[i] >= s2[i]
    }
    
    return s1LeS2 || s1GeS2;
}