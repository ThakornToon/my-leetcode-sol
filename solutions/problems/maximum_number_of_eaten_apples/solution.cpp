class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        // min-heap: (rotten_day, count) เลือกกินที่จะเน่าก่อน
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int eaten = 0;
        int day = 0;
        
        while (day < n || !pq.empty()) {
            // เพิ่มแอปเปิ้ลใหม่ของวันนี้ (ถ้ายังอยู่ในช่วง)
            if (day < n && apples[day] > 0) {
                pq.push({day + days[day], apples[day]});
            }
            
            // ลบแอปเปิ้ลที่เน่าแล้ว (expiry <= day)
            while (!pq.empty() && pq.top().first <= day) {
                pq.pop();
            }
            
            // กินแอปเปิ้ล 1 ผล (ถ้ามี)
            if (!pq.empty()) {
                auto [rottenDay, count] = pq.top();
                pq.pop();
                eaten++;
                if (count > 1) {
                    pq.push({rottenDay, count - 1});
                }
            }
            
            day++;
        }
        
        return eaten;
    }
};