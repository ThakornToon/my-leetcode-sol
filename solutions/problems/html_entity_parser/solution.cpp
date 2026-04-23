class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, char> entities = {
            {"&quot;", '"'},
            {"&apos;", '\''},
            {"&amp;", '&'},
            {"&gt;", '>'},
            {"&lt;", '<'},
            {"&frasl;", '/'}
        };
        
        string result;
        int n = text.length();
        
        for (int i = 0; i < n; i++) {
            if (text[i] == '&') {
                bool found = false;
                for (auto& [entity, ch] : entities) {
                    if (text.substr(i, entity.length()) == entity) {
                        result += ch;
                        i += entity.length() - 1;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    result += text[i];
                }
            } else {
                result += text[i];
            }
        }
        
        return result;
    }
};