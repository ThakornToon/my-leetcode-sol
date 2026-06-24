class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right && s[left] == s[right]) {
            char target = s[left];
            
            // ลบตัวอักษรที่เหมือนกันทางซ้าย
            while (left <= right && s[left] == target) {
                left++;
            }
            
            // ลบตัวอักษรที่เหมือนกันทางขวา
            while (left <= right && s[right] == target) {
                right--;
            }
        }
        
        return right - left + 1;
    }
};