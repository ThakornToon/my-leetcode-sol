class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> events;
        
        for (const auto& trip : trips) {
            events.push_back({trip[1], trip[0]});  // ขึ้นรถ
            events.push_back({trip[2], -trip[0]}); // ลงรถ
        }
        
        // เรียงตามตำแหน่ง
        sort(events.begin(), events.end());
        
        int current = 0;
        for (const auto& event : events) {
            current += event.second;
            if (current > capacity) {
                return false;
            }
        }
        
        return true;
    }
};