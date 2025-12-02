class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        
        // 1. คำนวณระยะห่างจากคนนั่งที่ใกล้ที่สุดทางซ้าย
        vector<int> left(n, n);  // เริ่มต้นด้วยค่ามากๆ
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                left[i] = 0;
            } else if (i > 0) {
                left[i] = left[i-1] + 1;
            }
        }
        
        // 2. คำนวณระยะห่างจากคนนั่งที่ใกล้ที่สุดทางขวา
        vector<int> right(n, n);
        for (int i = n-1; i >= 0; i--) {
            if (seats[i] == 1) {
                right[i] = 0;
            } else if (i < n-1) {
                right[i] = right[i+1] + 1;
            }
        }
        
        // 3. หาค่ามากสุดของ min(ซ้าย, ขวา)
        int maxDist = 0;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 0) {
                int dist = min(left[i], right[i]);
                maxDist = max(maxDist, dist);
            }
        }
        
        return maxDist;
    }
};