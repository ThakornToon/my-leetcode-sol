class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = 0;
        
        // หาบ้านที่อยู่ไกลสุดจากบ้านแรกที่มีสีต่างกัน
        for (int i = n - 1; i >= 0; i--) {
            if (colors[i] != colors[0]) {
                maxDist = max(maxDist, i);
                break;
            }
        }
        
        // หาบ้านที่อยู่ไกลสุดจากบ้านสุดท้ายที่มีสีต่างกัน
        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[n - 1]) {
                maxDist = max(maxDist, n - 1 - i);
                break;
            }
        }
        
        return maxDist;
    }
};