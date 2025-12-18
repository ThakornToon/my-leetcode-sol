class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (c == 'c') {
                // ต้องมี 'b' และ 'a' ตามลำดับใน stack
                if (st.size() >= 2) {
                    char b = st.top(); st.pop();
                    char a = st.top(); st.pop();
                    
                    if (!(b == 'b' && a == 'a')) {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        
        return st.empty();
    }
};