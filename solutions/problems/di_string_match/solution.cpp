class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> result;
        
        int low = 0, high = s.length();
        
        for (char c : s) {
            if (c == 'I') {
                result.push_back(low++);
            } else {
                result.push_back(high--);
            }
        }
        
        result.push_back(low); // low == high
        
        return result;
    }
};