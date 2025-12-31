class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;  // เก็บตำแหน่งของ '('
        string result;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);  // เก็บตำแหน่งของ '('
            } else if (s[i] == ')') {
                // ดึงตำแหน่งของ '(' ที่ตรงกัน
                int start = st.top();
                st.pop();
                
                // Reverse substring ระหว่าง start+1 ถึง i-1
                reverse(s.begin() + start + 1, s.begin() + i);
            }
        }
        
        // ลบวงเล็บทั้งหมดออก
        string answer;
        for (char c : s) {
            if (c != '(' && c != ')') {
                answer.push_back(c);
            }
        }
        
        return answer;
    }
};