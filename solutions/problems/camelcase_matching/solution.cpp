class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> answer;
        
        for (const string& query : queries) {
            answer.push_back(matches(query, pattern));
        }
        
        return answer;
    }
private:
    bool matches(const string& query, const string& pattern) {
        int i = 0, j = 0;  // i for query, j for pattern
        
        while (i < query.length()) {
            if (j < pattern.length() && query[i] == pattern[j]) {
                i++;
                j++;
            } else if (islower(query[i])) {
                i++;
            } else {
                return false;
            }
        }
        
        return j == pattern.length();
    }
};