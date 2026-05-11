class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.length();
        string result(n, ' ');  // สร้าง string ขนาด n ที่มีช่องว่าง
        
        for (int i = 0; i < n; i++) {
            result[indices[i]] = s[i];
        }
        
        return result;
    }
};