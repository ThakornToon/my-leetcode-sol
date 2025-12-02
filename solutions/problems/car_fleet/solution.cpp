class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);
        
        // สร้างและคำนวณเวลา (position, time to target)
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
        
        // เรียงจากตำแหน่งสูงไปต่ำ (ใกล้ target ไปไกล)
        sort(cars.begin(), cars.end(), greater<pair<int, double>>());
        
        int fleets = 0; // กลุ่ม
        double currentMaxTime = 0.0;
        
        // คิดจากตำแหน่งใกล้สุดก่อน
        for (int i = 0; i < n; i++) {
            double time = cars[i].second;
            
            // ถ้าเวลา > currentMaxTime → fleet ใหม่
            if (time > currentMaxTime) {
                fleets++;
                currentMaxTime = time;
            }
            // ถ้า time <= currentMaxTime → รวม fleet เดียวกัน (ไม่ต้องทำอะไร)
        }
        
        return fleets;
    }
};