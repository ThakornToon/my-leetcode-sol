class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        
        unordered_map<int, int> rankMap;
        int rank = 1;
        
        for (int num : sorted) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }
        
        vector<int> result;
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }
        
        return result;
    }
};