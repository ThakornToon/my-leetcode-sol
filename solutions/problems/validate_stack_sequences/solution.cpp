class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int pushIndex = 0;
        
        for (int target : popped) {
            // push จนกว่าจะเจอ target ที่ top ของ stack
            while (st.empty() || st.top() != target) {
                if (pushIndex >= pushed.size()) {
                    return false;
                }
                st.push(pushed[pushIndex++]);
            }
            
            // pop target
            st.pop();
        }
        
        return st.empty();
    }
};