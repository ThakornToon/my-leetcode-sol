class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.length();
        vector<vector<int>> positions(26);
        
        // เก็บตำแหน่งของแต่ละตัวอักษร
        for (int i = 0; i < n; i++) {
            positions[s[i] - 'A'].push_back(i);
        }
        
        int result = 0;
        
        // สำหรับแต่ละตัวอักษร
        for (int c = 0; c < 26; c++) {
            int m = positions[c].size();
            
            // สำหรับแต่ละตำแหน่งของตัวอักษรนี้
            for (int i = 0; i < m; i++) {
                int current = positions[c][i];
                
                // ตำแหน่งก่อนหน้า (หรือ -1 ถ้าไม่มี)
                int prev = (i > 0) ? positions[c][i - 1] : -1;
                
                // ตำแหน่งถัดไป (หรือ n ถ้าไม่มี)
                int next = (i < m - 1) ? positions[c][i + 1] : n;
                
                // จำนวน substring ที่ตัวอักษรนี้เป็น unique
                int left = current - prev;
                int right = next - current;
                result += left * right;
            }
        }
        
        return result;
    }
};