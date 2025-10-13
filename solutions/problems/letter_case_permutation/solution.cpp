class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        backtrack(s, 0, "", result);
        return result;
    }
    
private:
    void backtrack(const string& s, int index, string current, vector<string>& result) {
        if (index == s.length()) {
            result.push_back(current);
            return;
        }
        
        char c = s[index];
        if (isdigit(c)) {
            backtrack(s, index + 1, current + c, result);
        } else {
            backtrack(s, index + 1, current + (char)tolower(c), result);
            backtrack(s, index + 1, current + (char)toupper(c), result);
        }
    }
};