int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int maxLength = 0;
    int charIndex[128] = {0};
    int left = 0;
    for (int right = 0; right < n; right++) {
        left = (left < charIndex[s[right]]) ? charIndex[s[right]] : left;
        charIndex[s[right]] = right+1;
        maxLength = (maxLength < right - left + 1) ? right - left + 1 : maxLength;
    }
        
    return maxLength;
}