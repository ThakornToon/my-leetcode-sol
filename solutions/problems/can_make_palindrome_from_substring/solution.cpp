class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        // prefix sum สำหรับแต่ละตัวอักษร
        vector<vector<int>> prefix(n + 1, vector<int>(26, 0));
        
        // สร้าง prefix sum array
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];  // copy จากตัวก่อนหน้า
            int idx = s[i] - 'a';
            prefix[i + 1][idx]++;  // เพิ่ม count สำหรับตัวอักษรนี้
        }
        
        vector<bool> result;
        
        for (auto& query : queries) {
            int left = query[0];
            int right = query[1];
            int k = query[2];
            
            // นับจำนวนตัวอักษรแต่ละตัวใน substring
            vector<int> charCount(26, 0);
            for (int i = 0; i < 26; i++) {
                charCount[i] = prefix[right + 1][i] - prefix[left][i];
            }
            
            // นับจำนวนตัวอักษรที่มีจำนวนคี่
            int oddCount = 0;
            for (int i = 0; i < 26; i++) {
                if (charCount[i] % 2 == 1) {
                    oddCount++;
                }
            }
            
            // สำหรับ palindrome: ต้องมีตัวอักษรจำนวนคี่ได้ไม่เกิน 1 ตัว
            // กรณี 1: ความยาวคู่ → oddCount เป็น 0, 2, 4, ...
            // กรณี 2: ความยาวคี่ → oddCount เป็น 1, 3, 5, ...
            // แต่เราสามารถเปลี่ยนตัวอักษรได้ k ครั้ง
            // การเปลี่ยน 1 ครั้งลด oddCount ได้ 2 (เปลี่ยนคู่หนึ่งให้เหมือนกัน)
            int neededChanges = oddCount / 2;
            
            result.push_back(neededChanges <= k);
        }
        
        return result;
    }
};