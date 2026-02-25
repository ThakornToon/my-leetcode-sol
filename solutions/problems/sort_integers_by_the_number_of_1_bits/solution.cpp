class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> pairs;  // (bits, value)
        
        for (int num : arr) {
            pairs.push_back({__builtin_popcount(num), num});
        }
        
        sort(pairs.begin(), pairs.end());
        
        vector<int> result;
        for (auto& p : pairs) {
            result.push_back(p.second);
        }
        
        return result;
    }
};