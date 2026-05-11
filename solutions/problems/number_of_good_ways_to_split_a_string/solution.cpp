class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        vector<int> prefix(n), suffix(n);
        
        unordered_set<char> leftSet, rightSet;
        
        // prefix
        for (int i = 0; i < n; i++) {
            leftSet.insert(s[i]);
            prefix[i] = leftSet.size();
        }
        
        // suffix
        for (int i = n - 1; i >= 0; i--) {
            rightSet.insert(s[i]);
            suffix[i] = rightSet.size();
        }
        
        // count
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] == suffix[i + 1]) {
                count++;
            }
        }
        
        return count;
    }
};