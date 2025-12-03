/*
1. ต้องจ่ายให้ทุกคนตาม อัตราส่วนเงินเดือนต่อประสิทธิภาพที่เท่ากัน = r = W / Q
2. แต่ละคนต้องได้อย่างน้อยเงินเดือนขั้นต่ำที่ตัวเองต้องการ

COST i = Qi * r

เรียงตาม r จากน้อยไปมาก
ใช้ max-heap หาคน k-1 คนก่อนหน้าที่มี quality น้อยที่สุด + ตัวคนที่กำหนด r อีก 1
ทุกครั้งที่มีคนใหม่ ลองให้เขาเป็นคนกำหนด r

ถ้าคนที่ r สูงอยู่ในทีม เราต้องใช้ r ของเขาเลยต้องให้คนที่ r สูงเป็นคนกำหนด(คนล่าสุดที่พิจารณา)
*/

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        
        // สร้าง vector ของ (ratio, quality)
        vector<pair<double, int>> workers;
        for (int i = 0; i < n; i++) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }
        
        // เรียงตาม ratio จากน้อยไปมาก
        sort(workers.begin(), workers.end());
        
        // Max-heap สำหรับเก็บ quality (เราต้องการลบคนที่ quality สูงสุด)
        priority_queue<int> maxHeap;
        int qualitySum = 0;
        double minCost = DBL_MAX;;
        
        for (int i = 0; i < n; i++) {
            double currentRatio = workers[i].first;
            int currentQuality = workers[i].second;
            
            qualitySum += currentQuality;
            
            // ถ้ามี >= k คน เอาคนที่ quality สูงสุดออก
            if (maxHeap.size() >= k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }
            // เพิ่มคนงานปัจจุบัน
            maxHeap.push(currentQuality);
            // ถ้ามีครบ k คน คำนวณ cost
            if (maxHeap.size() == k) {
                double cost = currentRatio * qualitySum;
                minCost = min(minCost, cost);
            }
        }
        
        return minCost;
    }
};