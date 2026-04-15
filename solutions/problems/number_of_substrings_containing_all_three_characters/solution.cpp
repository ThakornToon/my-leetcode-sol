class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> lastPos(3, -1);
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            lastPos[s[i] - 'a'] = i;
            
            int minLast = *min_element(lastPos.begin(), lastPos.end());
            if (minLast != -1) {
                result += minLast + 1;
            }
        }
        
        return result;
    }
};