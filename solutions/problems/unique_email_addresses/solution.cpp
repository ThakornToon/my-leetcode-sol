class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;
        
        for (const string& email : emails) {
            stringstream ss;
            bool inLocal = true;
            bool afterPlus = false;
            
            for (char c : email) {
                if (c == '@') {
                    inLocal = false;
                    afterPlus = false;
                }
                
                if (inLocal) {
                    if (c == '+') {
                        afterPlus = true;
                        continue;
                    }
                    if (afterPlus) continue;
                    if (c == '.') continue;
                }
                
                ss << c;
            }
            
            uniqueEmails.insert(ss.str());
        }
        
        return uniqueEmails.size();
    }
};