class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactMatch;
        unordered_map<string, string> caseMatch;
        unordered_map<string, string> vowelMatch;
        
        // เตรียมข้อมูลจาก wordlist
        for (string& word : wordlist) {
            // 1. Exact match
            exactMatch.insert(word);
            
            // 2. Case-insensitive match
            string lower = toLower(word);
            if (!caseMatch.count(lower)) {
                caseMatch[lower] = word;
            }
            
            // 3. Vowel-insensitive match
            string devoweled = devowel(word);
            if (!vowelMatch.count(devoweled)) {
                vowelMatch[devoweled] = word;
            }
        }
        
        vector<string> result;
        
        for (string& query : queries) {
            // 1. Check exact match
            if (exactMatch.count(query)) {
                result.push_back(query);
                continue;
            }
            
            // 2. Check case-insensitive match
            string lower = toLower(query);
            if (caseMatch.count(lower)) {
                result.push_back(caseMatch[lower]);
                continue;
            }
            
            // 3. Check vowel-insensitive match
            string devoweled = devowel(query);
            if (vowelMatch.count(devoweled)) {
                result.push_back(vowelMatch[devoweled]);
                continue;
            }
            
            // 4. Not found
            result.push_back("");
        }
        
        return result;
    }
    
private:
    string toLower(const string& s) {
        string result = s;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
    
    string devowel(const string& s) {
        string result = toLower(s);
        for (char& c : result) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return result;
    }
};