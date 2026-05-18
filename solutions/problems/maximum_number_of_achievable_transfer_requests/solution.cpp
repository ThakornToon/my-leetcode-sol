class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        int maxCount = 0;
        
        // ทดลองทุก subset ของ requests (2^m รูปแบบ)
        for (int mask = 0; mask < (1 << m); mask++) {
            vector<int> balance(n, 0);
            int count = 0;
            
            // ประมวลผล requests ใน subset นี้
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    count++;
                    balance[requests[i][0]]--;
                    balance[requests[i][1]]++;
                }
            }
            
            // ตรวจสอบว่า balance ทุกตัวเป็น 0
            bool valid = true;
            for (int b : balance) {
                if (b != 0) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                maxCount = max(maxCount, count);
            }
        }
        
        return maxCount;
    }
};