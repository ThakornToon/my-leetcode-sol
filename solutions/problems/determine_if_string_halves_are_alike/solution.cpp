class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int half = n / 2;
        int count1 = 0, count2 = 0;
        
        for (int i = 0; i < half; i++) {
            if (isVowel(s[i])) count1++;
            if (isVowel(s[i + half])) count2++;
        }
        
        return count1 == count2;
    }
};