class Solution {
private:
    bool chaeck_pa(string &s) {
        int len = s.length();
        for (int i = 0; i < len - i; i++) {
            if (s[i] != s[len - i - 1]) {
                return false;
            }
        }
        return true;
    }
    void backtrack(string &s, vector<vector<string>> &ans, vector<string> &store, int start) {
        if (start == s.length()) {
            ans.push_back(store);
            return;
        }
        for (int end = start; end < s.length(); end++) {
            string sub = s.substr(start, end - start + 1);
            if (chaeck_pa(sub)) {
                store.push_back(sub);
                backtrack(s, ans, store, end + 1);
                store.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> store;
        backtrack(s, ans, store, 0);
        return ans;
    }
};