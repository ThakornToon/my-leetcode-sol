bool isIsomorphic(char* s, char* t) {
    char ascii[127] = {0};
    for (int i = 0; i < strlen(s); i++) {
        if (ascii[s[i]] == 0) {
            ascii[s[i]] = t[i];
        }
        else {
            if (ascii[s[i]] != t[i]) {
                return false;
            }
        }
    }
    memset(ascii, 0, sizeof(ascii));
    for (int i = 0; i < strlen(t); i++) {
        if (ascii[t[i]] == 0) {
            ascii[t[i]] = s[i];
        }
        else {
            if (ascii[t[i]] != s[i]) {
                return false;
            }
        }
    }

    return true;
}