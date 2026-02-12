int longestBalanced(char* s) {
    int n = strlen(s);
    int max_len = 0;
    
    // prefix[i][c] = ความถี่ของตัวอักษร c ใน s[0..i-1]
    int prefix[n + 1][26];
    memset(prefix, 0, sizeof(prefix));
    
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            prefix[i + 1][c] = prefix[i][c];
        }
        prefix[i + 1][s[i] - 'a']++;
    }
    
    // ตรวจสอบทุกช่วง i..j
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int target_freq = -1;
            bool balanced = true;
            
            for (int c = 0; c < 26; c++) {
                int freq = prefix[j + 1][c] - prefix[i][c];
                if (freq > 0) {
                    if (target_freq == -1) {
                        target_freq = freq;
                    } else if (freq != target_freq) {
                        balanced = false;
                        break;
                    }
                }
            }
            
            if (balanced) {
                int len = j - i + 1;
                if (len > max_len) {
                    max_len = len;
                }
            }
        }
    }
    
    return max_len;
}