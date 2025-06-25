class Solution {
private:
    void reverse(string& s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
    
    void cleanSpaces(string& s) {
        int n = s.length();
        int i = 0, j = 0;
        
        while (j < n) {
            while (j < n && s[j] == ' ') j++; // ข้ามช่องว่าง
            while (j < n && s[j] != ' ') s[i++] = s[j++]; // ย้ายคำ
            while (j < n && s[j] == ' ') j++; // ข้ามช่องว่างต่อ
            if (j < n) s[i++] = ' '; // เพิ่มช่องว่างระหว่างคำ
        }
        
        s.resize(i); // ปรับขนาดสตริง
    }
public:
    string reverseWords(string s) {
        // 1. ลบช่องว่างส่วนเกิน
        cleanSpaces(s);
        
        int n = s.length();
        if (n == 0) return s;
        
        // 2. Reverse ทั้งสตริง
        reverse(s, 0, n - 1);
        
        // 3. Reverse แต่ละคำ
        n = s.length();
        int i = 0, j = 0;
        
        while (i < n) {
            while (j < n && s[j] != ' ') j++;
            reverse(s, i, j - 1);
            i = j + 1;
            j = i;
        }
        return s;
    }
};