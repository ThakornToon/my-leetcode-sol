class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int start = rounds[0];
        int end = rounds.back();
        
        vector<int> result;
        
        if (start <= end) {
            for (int i = start; i <= end; i++) {
                result.push_back(i);
            }
        } else {
            for (int i = 1; i <= end; i++) {
                result.push_back(i);
            }
            for (int i = start; i <= n; i++) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};