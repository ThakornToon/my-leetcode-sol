class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> count(26, 0);
        vector<bool> inStack(26, false);
        stack<char> st;
        
        // นับความถี่ของแต่ละตัวอักษร
        for (char c : s) {
            count[c - 'a']++;
        }
        
        for (char c : s) {
            count[c - 'a']--;  // ลดความถี่ของตัวอักษรปัจจุบัน
            
            if (inStack[c - 'a']) continue;  // ข้ามถ้ามีใน Stack แล้ว
            
            // นำตัวอักษรใน Stack ที่มากกว่าออกถ้ายังมีเหลือในสตริง
            while (!st.empty() && c < st.top() && count[st.top() - 'a'] > 0) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(c);
            inStack[c - 'a'] = true;
        }
        
        // สร้างสตริงผลลัพธ์จาก Stack
        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};