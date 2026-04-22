class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        int wordLen = queries[0].length();
        
        for (string& q : queries) {
            for (string& d : dictionary) {
                int diff = 0;
                for (int i = 0; i < wordLen; i++) {
                    if (q[i] != d[i]) diff++;
                    if (diff > 2) break;  // early exit
                }
                if (diff <= 2) {
                    result.push_back(q);
                    break;
                }
            }
        }
        
        return result;
    }
};