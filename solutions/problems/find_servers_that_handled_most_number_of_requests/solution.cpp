class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // min-heap: (finish_time, server_id) - เซิร์ฟเวอร์ที่กำลังทำงาน
        // เรียงตาม finish_time น้อยไปมาก
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        
        // set ของเซิร์ฟเวอร์ที่ว่าง
        set<int> available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }
        
        // นับจำนวน request ที่แต่ละ server ได้รับ
        vector<int> count(k, 0);
        
        for (int i = 0; i < arrival.size(); i++) {
            int time = arrival[i];
            int duration = load[i];
            
            // ปล่อยเซิร์ฟเวอร์ที่ทำงานเสร็จแล้ว
            while (!busy.empty() && busy.top().first <= time) {
                int serverId = busy.top().second;
                busy.pop();
                available.insert(serverId);
            }
            
            // ถ้าไม่มีเซิร์ฟเวอร์ว่าง → ข้าม request นี้
            if (available.empty()) continue;
            
            // หาเซิร์ฟเวอร์ที่ต้องการ: i % k ใช้ binary search บน set
            int target = i % k;
            auto it = available.lower_bound(target);
            
            // ถ้าไม่มีเซิร์ฟเวอร์ตั้งแต่ target ขึ้นไป → เอา server ตัวแรก
            if (it == available.end()) {
                it = available.begin();
            }
            
            int serverId = *it;
            available.erase(it);
            count[serverId]++;
            
            // เพิ่มเซิร์ฟเวอร์นี้ลงใน busy queue
            busy.push({time + duration, serverId});
        }
        
        // หาค่าสูงสุด
        int maxCount = *max_element(count.begin(), count.end());
        
        // เก็บ server ที่มี count == maxCount
        vector<int> result;
        for (int i = 0; i < k; i++) {
            if (count[i] == maxCount) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};