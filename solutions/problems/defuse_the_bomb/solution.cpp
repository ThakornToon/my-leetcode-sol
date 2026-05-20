class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        
        if (k == 0) {
            return result;
        }
        
        // ขยาย array สำหรับ circular
        vector<int> extended(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            extended[i] = code[i % n];
        }
        
        // prefix sum
        vector<int> prefix(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            prefix[i + 1] = prefix[i] + extended[i];
        }
        
        if (k > 0) {
            // ผลรวมในช่วง k ตัวถัดไป
            for (int i = 0; i < n; i++) {
                result[i] = prefix[i + k + 1] - prefix[i + 1];
            }
        } else {
            // ผลรวมในช่วง |k| ตัวก่อนหน้า
            int m = -k;  // เป็นค่าบวก
            for (int i = 0; i < n; i++) {
                result[i] = prefix[i + n] - prefix[i + n - m];
            }
        }
        
        return result;
    }
};