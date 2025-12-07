class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> signatures;
    
        for (string& s : words) {
            // count[0-25] = ตำแหน่งคู่, count[26-51] = ตำแหน่งคี่
            vector<int> count(52, 0);
            
            for (int i = 0; i < s.length(); i++) {
                int idx = s[i] - 'a';
                if (i % 2 == 0) {
                    count[idx]++;  // ตำแหน่งคู่
                } else {
                    count[idx + 26]++;  // ตำแหน่งคี่ (+26 offset)
                }
            }
            
            // แปลง count array เป็น string signature
            string signature;
            for (int c : count) {
                signature += to_string(c) + ",";
            }
            signatures.insert(signature);
        }
        
        return signatures.size();
    }
};