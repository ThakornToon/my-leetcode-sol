class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        // เริ่มต้นด้วยตัวเลข 1 หลัก (1-9)
        vector<int> current = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        // สร้างทีละหลักจนได้ n หลัก
        for (int level = 1; level < n; level++) {
            vector<int> next;
            
            for (int num : current) {
                int last_digit = num % 10;
                
                if (k == 0) {
                    // เพิ่มตัวเลขเดิม
                    next.push_back(num * 10 + last_digit);
                } else {
                    // เพิ่มด้วย last_digit + k
                    if (last_digit + k <= 9) {
                        next.push_back(num * 10 + (last_digit + k));
                    }
                    // เพิ่มด้วย last_digit - k
                    if (last_digit - k >= 0) {
                        next.push_back(num * 10 + (last_digit - k));
                    }
                }
            }
            
            current = next;
        }
        
        return current;
    }
};