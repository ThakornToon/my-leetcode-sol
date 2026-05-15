class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        string result;
        int count = 0;
        
        // เติมจากขวาไปซ้าย
        for (int i = s.length() - 1; i >= 0; i--) {
            result.push_back(s[i]);
            count++;
            if (count % 3 == 0 && i != 0) {
                result.push_back('.');
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};