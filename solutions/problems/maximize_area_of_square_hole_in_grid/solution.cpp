class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // เรียงลำดับ bars
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        // หา consecutive bars สูงสุดสำหรับ horizontal
        int maxH = 1;  // อย่างน้อย 1 bar ถ้ามี bars
        if (!hBars.empty()) {
            int current = 1;
            for (int i = 0; i < hBars.size() - 1; i++) {
                if (hBars[i] + 1 == hBars[i + 1]) {
                    current++;
                    maxH = max(maxH, current);
                } else {
                    current = 1;
                }
            }
            maxH = max(maxH, current);
        } else {
            maxH = 0;  // ไม่มี horizontal bars
        }
        
        // หา consecutive bars สูงสุดสำหรับ vertical
        int maxV = 1;
        if (!vBars.empty()) {
            int current = 1;
            for (int i = 0; i < vBars.size() - 1; i++) {
                if (vBars[i] + 1 == vBars[i + 1]) {
                    current++;
                    maxV = max(maxV, current);
                } else {
                    current = 1;
                }
            }
            maxV = max(maxV, current);
        } else {
            maxV = 0;  // ไม่มี vertical bars
        }
        
        // side length = min(maxH, maxV) + 1
        int side = min(maxH, maxV) + 1;
        return side * side;
    }
};