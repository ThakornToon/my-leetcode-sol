class Solution {
private:
    const int MOD = 1000000007;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> engineers;
        for (int i = 0; i < n; i++) {
            engineers.push_back({efficiency[i], speed[i]});
        }
        
        // เรียงตาม efficiency จากมากไปน้อย
        sort(engineers.begin(), engineers.end(), greater<pair<int, int>>());
        
        // Min-heap สำหรับ speed
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sumSpeed = 0;
        long long maxPerf = 0;
        
        for (auto& eng : engineers) {
            int eff = eng.first;
            int spd = eng.second;
            
            // ถ้า heap เต็มแล้ว ให้เอาความเร็วน้อยที่สุดออก
            if (minHeap.size() == k) {
                sumSpeed -= minHeap.top();
                minHeap.pop();
            }
            
            // เพิ่มความเร็วปัจจุบัน
            minHeap.push(spd);
            sumSpeed += spd;
            
            // คำนวณประสิทธิภาพ
            long long perf = sumSpeed * eff;
            maxPerf = max(maxPerf, perf);
        }
        
        return (int)(maxPerf % MOD);
    }
};