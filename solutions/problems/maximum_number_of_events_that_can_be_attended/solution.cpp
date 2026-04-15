class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
         // เรียงตาม start day
        sort(events.begin(), events.end());
        
        // min-heap เก็บ end day
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i = 0;
        int n = events.size();
        int day = 1;
        int count = 0;
        
        while (i < n || !pq.empty()) {
            // เพิ่ม events ที่เริ่มในวันนี้
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }
            
            // ลบ events ที่ expired
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            
            // เข้าร่วม event ที่ end เร็วที่สุด
            if (!pq.empty()) {
                pq.pop();
                count++;
            }
            
            day++;
        }
        
        return count;
    }
};