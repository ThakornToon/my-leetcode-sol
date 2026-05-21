class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;
        
        // Store all prefixes of arr1
        for (int num : arr1) {
            string s = to_string(num);
            for (int i = 1; i <= s.length(); i++) {
                prefixes.insert(s.substr(0, i));
            }
        }
        
        int maxLen = 0;
        
        // Check prefixes of arr2
        for (int num : arr2) {
            string s = to_string(num);
            for (int i = 1; i <= s.length(); i++) {
                // Match with prefix of arr1
                if (prefixes.count(s.substr(0, i))) {
                    maxLen = max(maxLen, i);
                }
            }
        }
        
        return maxLen;
    }
};