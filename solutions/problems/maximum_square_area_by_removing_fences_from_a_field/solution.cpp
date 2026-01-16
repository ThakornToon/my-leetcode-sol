class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;
        
        // เพิ่มขอบเขต (fences ขอบนอกที่ไม่สามารถ remove ได้)
        vector<int> hPoints = hFences;
        hPoints.push_back(1);
        hPoints.push_back(m);
        sort(hPoints.begin(), hPoints.end());
        
        vector<int> vPoints = vFences;
        vPoints.push_back(1);
        vPoints.push_back(n);
        sort(vPoints.begin(), vPoints.end());
        
        // สร้าง set ของระยะห่างที่เป็นไปได้สำหรับแนวนอน
        unordered_set<int> hDistances;
        int hSize = hPoints.size();
        for (int i = 0; i < hSize; i++) {
            for (int j = i + 1; j < hSize; j++) {
                hDistances.insert(hPoints[j] - hPoints[i]);
            }
        }
        
        // สร้าง set ของระยะห่างที่เป็นไปได้สำหรับแนวตั้ง
        unordered_set<int> vDistances;
        int vSize = vPoints.size();
        for (int i = 0; i < vSize; i++) {
            for (int j = i + 1; j < vSize; j++) {
                vDistances.insert(vPoints[j] - vPoints[i]);
            }
        }
        
        // หา common distance ที่มากที่สุด
        int maxSide = 0;
        for (int dist : hDistances) {
            if (vDistances.count(dist)) {
                maxSide = max(maxSide, dist);
            }
        }
        
        if (maxSide == 0) {
            return -1;  // ไม่สามารถสร้างจัตุรัสได้
        }
        
        long long area = (long long)maxSide * maxSide;
        return (int)(area % MOD);
    }
};