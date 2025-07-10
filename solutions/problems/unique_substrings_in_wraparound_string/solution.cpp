class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> max_len(26, 0); // เก็บความยาวสูงสุดที่ลงท้ายด้วยแต่ละตัวอักษร
        int current_max = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && (s[i] - s[i-1] == 1 || s[i-1] - s[i] == 25)) {
                current_max++;
            } else {
                current_max = 1;
            }
            
            max_len[s[i] - 'a'] = max(max_len[s[i] - 'a'], current_max);
        }
        
        return accumulate(max_len.begin(), max_len.end(), 0);
    }
};