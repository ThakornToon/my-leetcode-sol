class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        
        for (const string& pattern : patterns) {
            // string::find คืนค่า npos ถ้าไม่พบ
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }
        
        return count;
    }
};