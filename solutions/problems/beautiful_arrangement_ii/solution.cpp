class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        int left = 1, right = n;
        
        // สร้าง k-1 ความต่างโดยสลับระหว่างต่ำและสูง
        for (int i = 0; i < k; i++) {
            if (i % 2 != 0) {
                result.push_back(left++);
            } else {
                result.push_back(right--);
            }
        }
        
        // เติมส่วนที่เหลือ
        if (k % 2 != 1) {
            // k คู่ -> เติมจากซ้ายไปขวา
            while (left <= right) {
                result.push_back(left++);
            }
        } else {
            // k คี่ -> เติมจากขวาไปซ้าย
            while (left <= right) {
                result.push_back(right--);
            }
        }
        
        return result;
    }
};