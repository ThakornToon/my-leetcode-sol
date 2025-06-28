class Solution {
public:
    string decodeString(string s) {
        vector<pair<string, int>> st;
        int nextNum = 0;
        string currStr = "";
        for (auto &ch : s) {
            if (ch == '[') {
                st.push_back({currStr, nextNum});
                currStr = "";
                nextNum = 0;
            } else if (ch == ']') {
                auto [prevStr, currNum] = st.back();
                st.pop_back();
                string temp = currStr;
                while (currNum > 1) {
                    currStr += temp;
                    currNum--;
                }
                currStr = prevStr + currStr;
            } else if (isdigit(ch)) {
                nextNum = (nextNum * 10) + ch - '0';
            } else {
                currStr += ch;
            }
        }
        return currStr;
    }
};