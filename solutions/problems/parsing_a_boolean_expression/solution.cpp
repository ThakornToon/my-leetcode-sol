class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        
        for (char c : expression) {
            if (c == ',') continue;
            
            if (c == ')') {
                // เก็บ operand ทั้งหมดจนเจอ operator
                vector<bool> operands;
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    if (top == 't') operands.push_back(true);
                    else if (top == 'f') operands.push_back(false);
                    st.pop();
                }
                st.pop(); // ลบ '('
                
                // ดึง operator
                char op = st.top();
                st.pop();
                
                // ประเมินผล
                bool result;
                if (op == '!') {
                    result = !operands[0];
                } else if (op == '&') {
                    result = true;
                    for (bool val : operands) {
                        result &= val;
                    }
                } else if (op == '|') {
                    result = false;
                    for (bool val : operands) {
                        result |= val;
                    }
                }
                
                // เก็บผลลัพธ์กลับเข้า stack
                st.push(result ? 't' : 'f');
            } else {
                st.push(c);
            }
        }
        
        return st.top() == 't';
    }
};