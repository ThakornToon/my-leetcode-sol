class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<pair<int, int>> items; // (value, label)
        
        for (int i = 0; i < n; i++) {
            items.emplace_back(values[i], labels[i]);
        }
        
        // เรียงจากมากไปน้อยตาม value
        sort(items.begin(), items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        unordered_map<int, int> labelCount;
        int sum = 0;
        int selected = 0;
        
        for (int i = 0; i < n && selected < numWanted; i++) {
            int value = items[i].first;
            int label = items[i].second;
            
            if (labelCount[label] < useLimit) {
                sum += value;
                labelCount[label]++;
                selected++;
            }
        }
        
        return sum;

    }
};