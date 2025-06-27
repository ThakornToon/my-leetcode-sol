class Solution {
private:
    bool isValid(const string& s) { 
        int balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else if (c == ')') balance--;
            if (balance < 0) return false;
        }
        return balance == 0;
    }
    void backtrack(const string& s, int start, int left_rem, int right_rem, vector<string>& result) {
        if (left_rem == 0 && right_rem == 0) {
            if (isValid(s)) {
                result.push_back(s);
            }
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (i > start && s[i] == s[i-1]) continue; // ถ้าซ้ำกันลบตัวไหนก็เหมือนกัน
            if (s[i] == '(' && left_rem > 0) {
                string new_str = s.substr(0, i) + s.substr(i+1);
                backtrack(new_str, i, left_rem - 1, right_rem, result);
            } else if (s[i] == ')' && right_rem > 0) {
                string new_str = s.substr(0, i) + s.substr(i+1);
                backtrack(new_str, i, left_rem, right_rem - 1, result);
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        int left_rem = 0, right_rem = 0;
        // ดูว่าเราควรลบวงเล็บเปิดซ้ายหรือขวาเท่าไรเพื่อให้ได้ valid with the minimum number of removals
        for (char c : s) {
            if (c == '(') {
                left_rem++;
            } else if (c == ')') {
                if (left_rem > 0) left_rem--;
                else right_rem++;
            }
        }
        
        backtrack(s, 0, left_rem, right_rem, result);
        return result;
    }
};