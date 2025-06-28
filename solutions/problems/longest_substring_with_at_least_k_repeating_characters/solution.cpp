class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++; // นับความถี่ตัวอักษรต่างๆในสตริงปัจจุบัน
        
        for (auto& [c, cnt] : freq) { 
            if (cnt < k) { // ตัวอักษรไหนในสตริงปัจจุบันที่มีจำนวนน้อยกว่า k แปลว่าตัวอักษรนั้นจะไม่อยู่ในสตริงที่เราต้องการ (ใช้เป็นตัวแบ่งสตริง)
                int max_len = 0;
                int start = 0;
                int pos = s.find(c); // หาตำแหน่งตัวอักษรนั้น
                while (pos != string::npos) { // หากพบ
                    max_len = max(max_len, longestSubstring(s.substr(start, pos - start), k));
                    start = pos + 1;
                    pos = s.find(c, start);
                }
                max_len = max(max_len, longestSubstring(s.substr(start), k));
                return max_len;
            }
        }
        
        return s.size(); // หากในสตริทุกตัวมีจำนวน >= k
    }
};