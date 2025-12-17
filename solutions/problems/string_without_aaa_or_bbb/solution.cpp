class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string result;
        
        while (a > 0 || b > 0) {
            if (a > b) {
                // วาง "aab"
                if (a > 0) { result += 'a'; a--; }
                if (a > 0) { result += 'a'; a--; }
                if (b > 0) { result += 'b'; b--; }
            } else if (b > a) {
                // วาง "bba"
                if (b > 0) { result += 'b'; b--; }
                if (b > 0) { result += 'b'; b--; }
                if (a > 0) { result += 'a'; a--; }
            } else {
                // เท่ากัน สลับกัน
                if (a > 0) { result += 'a'; a--; }
                if (b > 0) { result += 'b'; b--; }
            }
        }
        
        return result;
    }
};