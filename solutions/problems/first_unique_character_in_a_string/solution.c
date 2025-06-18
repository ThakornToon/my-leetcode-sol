int firstUniqChar(char* s) {
    int ans = 0;
    int letters[26] = {0};
    for (int i = 0; i < strlen(s); i++){
        letters[s[i] - 'a']++;
        if (letters[s[ans] - 'a'] > 1) {
            ans++;  
            while (ans <= i) {
                if (letters[s[ans] - 'a'] == 1) {
                    break;
                } else {
                    ans++;
                }
            }
        }
    }
    if (ans == strlen(s)) {
        return -1;
    } else {
        return ans;
    }
}