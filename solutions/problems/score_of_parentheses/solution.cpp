class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int currentScore = 0;
        
        for (char c : s) {
            if (c == '(') {
                // push current score and reset for new group
                st.push(currentScore);
                currentScore = 0;
            } else {  // c == ')'
                // currentScore อาจเป็น 0 หรือมีค่าบางอย่าง
                currentScore = st.top() + max(2 * currentScore, 1);
                st.pop();
            }
        }
        
        return currentScore;
    }
};