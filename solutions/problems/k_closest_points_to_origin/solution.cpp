class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap โดยเก็บคู่ (distance, index)
        // เราต้องการให้ตัวที่มีระยะทางมากอยู่ด้านบนเพื่อสามารถ pop ออกได้
        priority_queue<pair<int, int>> maxHeap;
        
        for (int i = 0; i < points.size(); i++) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            
            if (maxHeap.size() < k) {
                maxHeap.push({dist, i});
            } else if (dist < maxHeap.top().first) {
                maxHeap.pop();
                maxHeap.push({dist, i});
            }
        }
        
        // นำผลลัพธ์ออกจาก heap
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            int idx = maxHeap.top().second;
            result.push_back(points[idx]);
            maxHeap.pop();
        }
        
        return result;
    }
};