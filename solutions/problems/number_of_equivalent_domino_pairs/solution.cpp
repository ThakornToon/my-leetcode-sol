class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<vector<int>> count(10, vector<int>(10, 0));
        int result = 0;
        
        for (const auto& domino : dominoes) {
            int a = domino[0];
            int b = domino[1];
            int x = min(a, b);
            int y = max(a, b);
            
            // domino ปัจจุบันจะจับคู่กับ domino เดิมทุกอันที่เคยเห็น
            result += count[x][y];
            count[x][y]++;
        }
        
        return result;
    }
};