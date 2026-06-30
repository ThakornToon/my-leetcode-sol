class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> repeated;
        
        for (int i = 0; i + 10 <= s.size(); i++) {
            string seq = s.substr(i, 10);
            if (seen.find(seq) != seen.end()) {
                repeated.insert(seq);
            }
            seen.insert(seq);
        }
        
        return vector<string>(repeated.begin(), repeated.end());
    }
};