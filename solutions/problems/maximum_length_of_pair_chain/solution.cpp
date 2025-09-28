class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // เรียงลำดับตาม b (สิ้นสุด)
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int count = 1;
        int current_end = pairs[0][1];
        
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > current_end) {
                count++;
                current_end = pairs[i][1];
            }
        }
        
        return count;
    }
};