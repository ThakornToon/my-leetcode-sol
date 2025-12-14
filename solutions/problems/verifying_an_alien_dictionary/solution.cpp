class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> orderMap;
        for (int i = 0; i < order.length(); i++) {
            orderMap[order[i]] = i;
        }
        
        // เปรียบเทียบทีละคู่
        for (int i = 0; i < words.size() - 1; i++) {
            const string& w1 = words[i];
            const string& w2 = words[i + 1];
            
            int minLen = min(w1.length(), w2.length());
            bool equalPrefix = true;
            
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    if (orderMap[w1[j]] > orderMap[w2[j]]) {
                        return false;
                    }
                    equalPrefix = false;
                    break;
                }
            }
            
            // ตรวจสอบกรณีที่เป็น prefix
            if (equalPrefix && w1.length() > w2.length()) {
                return false;
            }
        }
        
        return true;
    }
};