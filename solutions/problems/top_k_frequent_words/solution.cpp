class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Count frequencies
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }
        
        // Custom comparator for sorting
        auto comparator = [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second; // Higher frequency first
            }
            return a.first < b.first; // Lexicographical order
        };
        
        // Convert to vector and sort
        vector<pair<string, int>> wordFreq(freq.begin(), freq.end());
        sort(wordFreq.begin(), wordFreq.end(), comparator);
        
        // Extract top k
        vector<string> result;
        for (int i = 0; i < k; i++) {
            result.push_back(wordFreq[i].first);
        }
        
        return result;
    }
};