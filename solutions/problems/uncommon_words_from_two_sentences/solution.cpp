class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
    
        // Function to process a sentence
        auto process = [&](const string& s) {
            stringstream ss(s);
            string word;
            while (ss >> word) {
                freq[word]++;
            }
        };
        
        process(s1);
        process(s2);
        
        vector<string> result;
        for (auto& [word, count] : freq) {
            if (count == 1) result.push_back(word);
        }
        return result;
    }
};