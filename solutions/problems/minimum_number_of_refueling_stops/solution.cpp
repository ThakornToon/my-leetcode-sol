class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // Max-heap (priority queue โดย default เป็น max-heap)
        priority_queue<int> pq;
        
        int stops = 0;
        int i = 0;
        int currentFuel = startFuel;
        
        while (currentFuel < target) {
            // เก็บสถานีทั้งหมดที่ผ่านมา
            while (i < stations.size() && stations[i][0] <= currentFuel) {
                pq.push(stations[i][1]);  // เก็บจำนวนน้ำมัน
                i++;
            }
            
            // ถ้าไม่มีสถานีให้เติมแล้ว
            if (pq.empty()) {
                return -1;
            }
            
            // เติมจากสถานีที่มีน้ำมันเยอะสุด
            currentFuel += pq.top();
            pq.pop();
            stops++;
        }
        
        return stops;
    }
};