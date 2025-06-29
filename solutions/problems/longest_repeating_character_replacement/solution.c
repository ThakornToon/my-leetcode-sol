int characterReplacement(char* s, int k) {
    int left = 0;
    int right = 0;
    int maxWin = 0;
    int mostChar = 0;
    int ch[26] = {0};
    int len = strlen(s);
    while (right < len) {
        char c = s[right] - 'A';
        ch[c]++;
        if (ch[c] > mostChar) {
            mostChar = ch[c];
        }
        if (right - left - mostChar + 1 > k) {
            ch[s[left] - 'A']--;
            left++;
        }
        if (maxWin < right - left + 1) {
            maxWin = right - left + 1;
        }
        right++;
    }
    return maxWin;
}