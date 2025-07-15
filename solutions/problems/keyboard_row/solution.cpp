class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // สร้าง mapping ของตัวอักษรแต่ละตัวว่าอยู่แถวใด
        unordered_map<char, int> rowMap = {
            {'q', 0}, {'w', 0}, {'e', 0}, {'r', 0}, {'t', 0}, {'y', 0}, {'u', 0}, {'i', 0}, {'o', 0}, {'p', 0},
            {'a', 1}, {'s', 1}, {'d', 1}, {'f', 1}, {'g', 1}, {'h', 1}, {'j', 1}, {'k', 1}, {'l', 1},
            {'z', 2}, {'x', 2}, {'c', 2}, {'v', 2}, {'b', 2}, {'n', 2}, {'m', 2}
        };
        
        vector<string> result;
        
        for (const string& word : words) {
            if (word.empty()) continue;
            
            // หาแถวของตัวอักษรตัวแรก (แปลงเป็นตัวพิมพ์เล็ก)
            int row = rowMap[tolower(word[0])];
            bool valid = true;
            
            // ตรวจสอบตัวอักษรที่เหลือ
            for (char c : word) {
                if (rowMap[tolower(c)] != row) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};