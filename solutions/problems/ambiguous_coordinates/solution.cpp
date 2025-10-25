class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> result;
        string num = s.substr(1, s.length() - 2); // เอาส่วนตัวเลข
        
        for (int i = 1; i < num.length(); i++) {
            // แบ่งงส่วนตัวเลข
            string left = num.substr(0, i);
            string right = num.substr(i);
            
            // แทรกจุดทศนิยม
            vector<string> leftOptions = makeNumbers(left);
            vector<string> rightOptions = makeNumbers(right);
            
            for (string l : leftOptions) {
                for (string r : rightOptions) {
                    result.push_back("(" + l + ", " + r + ")");
                }
            }
        }
        
        return result;
    }
    
    vector<string> makeNumbers(string s) {
        vector<string> options;
        int n = s.length();
        
        // กรณีไม่มีจุดทศนิยม
        if (s[0] != '0' || n == 1) {
            options.push_back(s);
        }
        
        // กรณีมีจุดทศนิยม
        for (int i = 1; i < n; i++) {
            string beforeDot = s.substr(0, i);
            string afterDot = s.substr(i);
            
            // ตรวจสอบส่วนก่อนจุด
            if (beforeDot[0] == '0' && beforeDot.length() > 1) continue;
            
            // ตรวจสอบส่วนหลังจุด
            if (afterDot.back() == '0') continue;
            
            options.push_back(beforeDot + "." + afterDot);
        }
        
        return options;
    }
};