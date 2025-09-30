class Solution {
public:
    int flipLights(int n, int presses) {
        string initial(n, '0');
        unordered_set<string> current{initial};
        
        for (int step = 0; step < presses; step++) {
            unordered_set<string> next_level;
            
            for (const string& state : current) {
                vector<function<string(string)>> operations = {
                    [](string s) { for (char& c : s) c = (c == '0' ? '1' : '0'); return s; },
                    [](string s) { for (int i = 0; i < s.size(); i += 2) s[i] = (s[i] == '0' ? '1' : '0'); return s; },
                    [](string s) { for (int i = 1; i < s.size(); i += 2) s[i] = (s[i] == '0' ? '1' : '0'); return s; },
                    [](string s) { for (int i = 0; i < s.size(); i++) if (i % 3 == 0) s[i] = (s[i] == '0' ? '1' : '0'); return s; }
                };
                
                for (auto& op : operations) {
                    next_level.insert(op(state));
                }
            }
            
            current = next_level;
        }
        
        return current.size();
    }
};