class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        
        for (const string& word : words) {
            int wordWeight = 0;
            
            // คำนวณน้ำหนักของคำ
            for (char c : word) {
                int letterIndex = c - 'a';
                wordWeight += weights[letterIndex];
            }
            
            // นำ modulo 26 และแมปเป็นตัวอักษร
            int remainder = wordWeight % 26;
            char mappedChar = 'z' - remainder;  // 0->'z', 1->'y', ..., 25->'a'
            result.push_back(mappedChar);
        }
        
        return result;
    }
};