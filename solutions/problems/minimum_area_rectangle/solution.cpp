class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        // จัดกลุ่มจุดตามค่า x
        unordered_map<int, vector<int>> xGroups;
        
        for (const auto& p : points) {
            xGroups[p[0]].push_back(p[1]);
        }
        
        // เรียงลำดับ y ในแต่ละกลุ่ม x
        for (auto& group : xGroups) {
            sort(group.second.begin(), group.second.end());
        }
        
        int minArea = INT_MAX;
        
        // ตรวจสอบทุกคู่ของแกน x
        vector<int> xs;
        for (const auto& group : xGroups) {
            xs.push_back(group.first);
        }
        sort(xs.begin(), xs.end());
        
        for (int i = 0; i < xs.size(); i++) {
            for (int j = i + 1; j < xs.size(); j++) {
                int x1 = xs[i];
                int x2 = xs[j];
                
                const vector<int>& y1s = xGroups[x1];
                const vector<int>& y2s = xGroups[x2];
                
                // หาค่า y ที่เหมือนกันในทั้งสองแกน x
                vector<int> commonYs;
                int p1 = 0, p2 = 0;
                
                while (p1 < y1s.size() && p2 < y2s.size()) {
                    if (y1s[p1] == y2s[p2]) {
                        commonYs.push_back(y1s[p1]);
                        p1++;
                        p2++;
                    } else if (y1s[p1] < y2s[p2]) {
                        p1++;
                    } else {
                        p2++;
                    }
                }
                
                // ถ้ามีค่า y ร่วมกันอย่างน้อย 2 ค่า
                if (commonYs.size() >= 2) {
                    // เรียงลำดับค่า y
                    
                    // หาพื้นที่ที่เล็กที่สุด
                    for (int k = 1; k < commonYs.size(); k++) {
                        int height = commonYs[k] - commonYs[k - 1];
                        int width = x2 - x1;
                        int area = height * width;
                        minArea = min(minArea, area);
                    }
                }
            }
        }
        
        return minArea == INT_MAX ? 0 : minArea;
    }
};