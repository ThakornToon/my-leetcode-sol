class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); i++) {
            projects.emplace_back(capital[i], profits[i]);
        }
        
        // เรียงตามทุนที่ต้องการ (capital)
        sort(projects.begin(), projects.end());
        
        priority_queue<int> maxHeap;
        int current = 0;
        
        for (int i = 0; i < k; i++) {
            // เพิ่มโครงการที่ทำได้ลงใน heap
            while (current < projects.size() && projects[current].first <= w) {
                maxHeap.push(projects[current].second);
                current++;
            }
            
            if (maxHeap.empty()) break;
            
            // เลือกโครงการที่ให้กำไรสูงสุด
            w += maxHeap.top();
            maxHeap.pop();
        }
        
        return w;
    }
};