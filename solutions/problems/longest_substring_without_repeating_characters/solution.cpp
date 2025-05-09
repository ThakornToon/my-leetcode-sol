class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        vector<int> charIndex(128, 0);
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            left = max(left, charIndex[s[right]]);
            charIndex[s[right]] = right+1;
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};