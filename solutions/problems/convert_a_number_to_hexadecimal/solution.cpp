class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        unsigned int n = num;
        const char* hexChars = "0123456789abcdef";
        string result;
        
        while (n > 0) {
            result += hexChars[n % 16];
            n /= 16;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};