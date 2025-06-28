class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int x1 = INT_MAX, y1 = INT_MAX;
        int x2 = INT_MIN, y2 = INT_MIN;
        long long total_area = 0;
        unordered_set<string> corner_set; // unordered_set ต้องการ hash function ที่เหมาะสมสำหรับประเภทข้อมูลที่เก็บ แต่มาตรฐาน C++ ไม่มี hash function สำหรับ std::pair โดย default

        for (auto& rect : rectangles) {
            int rx1 = rect[0], ry1 = rect[1];
            int rx2 = rect[2], ry2 = rect[3];

            // Update bounding rectangle
            x1 = min(x1, rx1);
            y1 = min(y1, ry1);
            x2 = max(x2, rx2);
            y2 = max(y2, ry2);

            // Calculate total area
            total_area += (long long)(rx2 - rx1) * (ry2 - ry1);

            // Check corners
            vector<pair<int, int>> corners = {
                {rx1, ry1}, {rx1, ry2}, {rx2, ry1}, {rx2, ry2}};

            for (auto& corner : corners) {
                string key = to_string(corner.first) + "," + to_string(corner.second);
                if (corner_set.count(key)) {
                    corner_set.erase(key);
                } else {
                    corner_set.insert(key);
                }
            }
        }

        // Check area
        long long bounding_area = (long long)(x2 - x1) * (y2 - y1);
        if (total_area != bounding_area) {
            return false;
        }

        // Check outer corners
        vector<pair<int, int>> outer_corners = {{x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}};
        for (auto& corner : outer_corners) {
            string key = to_string(corner.first) + "," + to_string(corner.second);
            if (!corner_set.count(key)) {
                return false;
            }
        }

        return corner_set.size() == 4;
    }
};