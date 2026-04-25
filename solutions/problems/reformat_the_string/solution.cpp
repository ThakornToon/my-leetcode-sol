class Solution {
public:
    string reformat(string s) {
        vector<char> letters, digits;
        
        for (char c : s) {
            if (isalpha(c)) {
                letters.push_back(c);
            } else {
                digits.push_back(c);
            }
        }
        
        int l = letters.size();
        int d = digits.size();
        
        if (abs(l - d) > 1) return "";
        
        string result;
        int i = 0, j = 0;
        
        if (l > d) {
            while (j < d) {
                result += letters[i++];
                result += digits[j++];
            }
            result += letters[i];
        } else if (d > l) {
            while (i < l) {
                result += digits[j++];
                result += letters[i++];
            }
            result += digits[j];
        } else {
            for (int k = 0; k < l; k++) {
                result += letters[k];
                result += digits[k];
            }
        }
        
        return result;
    }
};