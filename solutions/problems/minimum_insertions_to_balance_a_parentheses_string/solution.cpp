class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int insertions = 0;
        int i = 0;
        int n = s.length();
        
        while (i < n) {
            if (s[i] == '(') {
                st.push('(');
                i++;
            } else {
                // เจอ ')'
                if (i + 1 < n && s[i + 1] == ')') {
                    // มี '))'
                    i += 2;
                } else {
                    // ต้องแทรก ')'
                    insertions++;
                    i++;
                }
                
                if (!st.empty()) {
                    st.pop();
                } else {
                    // ต้องแทรก '('
                    insertions++;
                }
            }
        }
        
        // ปิด '(' ที่เหลือใน stack
        insertions += st.size() * 2;
        
        return insertions;
    }
};