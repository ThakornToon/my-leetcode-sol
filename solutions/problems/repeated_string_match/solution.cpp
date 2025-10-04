class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = "";
        int count = 0;
        int maxRepeat = b.length() / a.length() + 2;
        
        while (count < maxRepeat) {
            repeated += a;
            count++;
            
            // ตรวจสอบว่า b เป็น substring ของ repeated หรือไม่
            if (repeated.find(b) != string::npos) {
                return count;
            }
        }
        
        return -1;
    }
};