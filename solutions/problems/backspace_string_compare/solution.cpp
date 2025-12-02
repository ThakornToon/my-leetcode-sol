class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return buildString(s) == buildString(t);
    }
    
private:
    string buildString(string str) {
        string result;
        for (char c : str) {
            if (c == '#') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};