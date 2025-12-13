class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.length();
        
        // end[char] = จำนวน subsequence ที่ลงท้ายด้วยตัวอักษรนี้
        vector<int> end(26, 0);
        
        // สำหรับทุกตัวอักษรใน string
        for (char c : s) {
            int idx = c - 'a';
            
            // ผลรวมของ end ทั้งหมด + 1 (สำหรับ subsequence ใหม่ที่เริ่มด้วยตัวอักษรนี้)
            int sum = 1; // subsequence ที่มีแค่ตัวอักษรนี้ตัวเดียว
            for (int i = 0; i < 26; i++) {
                sum = (sum + end[i]) % MOD;
            }
            
            // อัปเดต end สำหรับตัวอักษรนี้
            end[idx] = sum;
        }
        
        // รวม end ทั้งหมด
        int result = 0;
        for (int i = 0; i < 26; i++) {
            result = (result + end[i]) % MOD;
        }
        
        return result;
    }
};