class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {    
        // 1. รวบรวม y-coordinates สำคัญทั้งหมด
        set<double> ySet;
        for (auto& sq : squares) {
            double y = sq[1];
            double top = y + sq[2];
            ySet.insert(y);
            ySet.insert(top);
        }

        vector<double> yCoords(ySet.begin(), ySet.end()); // เรียงแล้ว
        int m = yCoords.size();

        // 2. events[i] สร้าง events สำหรับแต่ละ yCoords[i] = y ที่เราลองแบ่งว่าควร active เมื่อใด
        vector<vector<pair<double, double>>> addEvents(m), removeEvents(m);

        for (auto& sq : squares) {
            // มุมซ้ายล่าง
            double x1 = sq[0];
            double y1 = sq[1];
            double side = sq[2];
            // มุมขวาบน
            double x2 = x1 + side;
            double y2 = y1 + side;
            
            // binary search หา index ของ y1 และ y2 ใน yCoords
            int idx1 = lower_bound(yCoords.begin(), yCoords.end(), y1) - yCoords.begin();
            int idx2 = lower_bound(yCoords.begin(), yCoords.end(), y2) - yCoords.begin();
            
            // intervals นี้ active ในช่วง [idx1, idx2-1]
            if (idx1 < idx2) {
                addEvents[idx1].push_back({x1, x2});
                removeEvents[idx2].push_back({x1, x2});
            }
        }
        
        // 3. คำนวณพื้นที่สะสมที่ y มีค่า yCoords[i]
        double totalArea = 0.0;
        vector<double> prefixArea(m, 0.0);
        multiset<pair<double, double>> active;  // (x_start, x_end)
        
        // ลองลากเส้น yCoords[i] = y ที่สำคัญ
        for (int i = 0; i < m - 1; i++) {
            double y1 = yCoords[i]; // เส้นก่อนหน้า
            double y2 = yCoords[i + 1]; // เส้นปัจจุบัน
            double height = y2 - y1;
            
            // เพิ่ม intervals ที่เริ่มที่ y1
            for (auto& interval : addEvents[i]) {
                active.insert(interval);
            }

            // ลบ intervals ที่สิ้นสุดที่ y1 (จาก removeEvents[i])
            for (auto& interval : removeEvents[i]) {
                auto it = active.find(interval);
                if (it != active.end()) {
                    active.erase(it);
                }
            }
            
            // คำนวณความกว้างรวมของ active intervals ช่วง y1 ถึง y2
            double width = 0.0;
            if (!active.empty()) {
                // แปลง multiset active เป็น vector เพื่อ merge intervals
                vector<pair<double, double>> intervals(active.begin(), active.end());
                // เรียงตาม x_start มาแล้ว
                
                // Merge intervals
                double curStart = intervals[0].first;
                double curEnd = intervals[0].second;
                
                for (int j = 1; j < intervals.size(); j++) {
                    if (intervals[j].first <= curEnd) {
                        // ซ้อนกัน → merge
                        curEnd = max(curEnd, intervals[j].second);
                    } else {
                        // ไม่ซ้อน → บวกช่วงที่แล้ว
                        width += (curEnd - curStart);
                        curStart = intervals[j].first;
                        curEnd = intervals[j].second;
                    }
                }
                width += (curEnd - curStart);
            }
            
            // พื้นที่ในช่วงนี้
            double area = width * height;
            totalArea += area;
            prefixArea[i + 1] = totalArea;
        }
        
        // 4. หาเส้นแบ่ง
        double targetArea = totalArea / 2.0;
        
        // Binary search หาช่วงที่ targetArea อยู่
        int idx = lower_bound(prefixArea.begin(), prefixArea.end(), targetArea) - prefixArea.begin();
        
        // กรณีแบ่งพอดี
        if (abs(prefixArea[idx] - targetArea) < 1e-5) {
            return yCoords[idx];
        }
        
        // เส้นแบ่งอยู่ระหว่าง yCoords[idx-1] และ yCoords[idx]
        double y1 = yCoords[idx - 1];
        double y2 = yCoords[idx];
        double areaBefore = prefixArea[idx - 1];
        double areaNeeded = targetArea - areaBefore;
        
        // คำนวณความกว้างในช่วงนี้
        double width = 0.0;
        multiset<pair<double, int>> activeInRange;
        
        // สร้าง active set สำหรับช่วงนี้
        for (int i = 0; i < idx; i++) {
            // เพิ่ม intervals
            for (auto& interval : addEvents[i]) {
                activeInRange.insert(interval);
            }
            // ลบ intervals
            for (auto& interval : removeEvents[i]) {
                auto it = activeInRange.find(interval);
                if (it != activeInRange.end()) {
                    activeInRange.erase(it);
                }
            }
        }
        
        // คำนวณ width
        vector<pair<double, double>> intervals(activeInRange.begin(), activeInRange.end());
        // เรียงตาม x_start มาแล้ว
                    
        double curStart = intervals[0].first;
        double curEnd = intervals[0].second;
            
        for (int j = 1; j < intervals.size(); j++) {
            if (intervals[j].first <= curEnd) {
                curEnd = max(curEnd, intervals[j].second);
            } else {
                width += (curEnd - curStart);
                curStart = intervals[j].first;
                curEnd = intervals[j].second;
            }
        }
        width += (curEnd - curStart);
            
        // คำนวณ dy
        double dy = areaNeeded / width;
        return y1 + dy;
    }
};