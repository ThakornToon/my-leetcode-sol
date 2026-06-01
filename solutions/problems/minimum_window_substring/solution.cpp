class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        
        // ใช้ unordered_map เก็บความถี่ของตัวอักษรใน t
        unordered_map<char, int> need;
        for (char c : t) {
            need[c]++;
        }
        
        unordered_map<char, int> have;
        int required = need.size();  // จำนวนตัวอักษรที่แตกต่างกัน
        int formed = 0;
        
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minLeft = 0;
        
        while (right < s.length()) {
            char c = s[right];
            have[c]++;
            
            // ตรวจสอบว่าตัวอักษรนี้ครบตามที่ต้องการหรือยัง
            if (need.count(c) && have[c] == need[c]) {
                formed++;
            }
            
            // พยายามหด window ทางซ้าย
            while (left <= right && formed == required) {
                c = s[left];
                
                // บันทึกผลลัพธ์
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }
                
                // ลบตัวอักษรทางซ้ายออก
                have[c]--;
                if (need.count(c) && have[c] + 1 == need[c]) {
                    formed--;
                }
                left++;
            }
            right++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};