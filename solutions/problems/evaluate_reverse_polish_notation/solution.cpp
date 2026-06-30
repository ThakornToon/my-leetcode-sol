class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& token : tokens) {
            if (isOperator(token)) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                int result = 0;
                if (token == "+") {
                    result = a + b;
                } else if (token == "-") {
                    result = a - b;
                } else if (token == "*") {
                    result = a * b;
                } else if (token == "/") {
                    result = a / b; 
                }
                
                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
    
private:
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
};