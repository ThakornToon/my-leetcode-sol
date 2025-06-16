class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        int current = 0;
        int sign = 1; 

        for (char ch : s) {
            if (isdigit(ch)) {
                current = current * 10 + (ch - '0');
            } else if (ch == '+') {
                result += sign * current;
                current = 0;
                sign = 1;
            } else if (ch == '-') {
                result += sign * current;
                current = 0;
                sign = -1;
            } else if (ch == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                result += sign * current;
                current = 0;
                int prev_sign = st.top();
                st.pop();
                int prev_result = st.top();
                st.pop();
                result *= prev_sign;
                result += prev_result;
            }
        }

        return result + sign * current;
    }
};