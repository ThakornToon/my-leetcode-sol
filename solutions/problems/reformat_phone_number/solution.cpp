class Solution {
public:
    string reformatNumber(string number) {
        // กรองเอาเฉพาะตัวเลข
        string digits;
        for (char c : number) {
            if (isdigit(c)) {
                digits += c;
            }
        }
        
        string result;
        int n = digits.length();
        int i = 0;
        
        while (i < n) {
            int remaining = n - i;
            
            if (remaining > 4) {
                result += digits.substr(i, 3) + "-";
                i += 3;
            } else if (remaining == 4) {
                result += digits.substr(i, 2) + "-" + digits.substr(i + 2, 2);
                i += 4;
            } else {
                result += digits.substr(i, remaining);
                i += remaining;
            }
        }
        
        return result;
    }
};