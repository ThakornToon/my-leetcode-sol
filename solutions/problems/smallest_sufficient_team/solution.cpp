class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        int m = people.size();
        
        // สร้าง mapping จากชื่อ skill ไป bit position (0..=16)
        unordered_map<string, int> skillToBit;
        for (int i = 0; i < n; i++) {
            skillToBit[req_skills[i]] = i;
        }
        
        // แปลงทักษะของแต่ละคนเป็น bitmask
        vector<int> peopleMask(m, 0);
        for (int i = 0; i < m; i++) {
            // bitmask ว่ามีทักษะไหนบ้าง
            for (const string& skill : people[i]) {
                if (skillToBit.count(skill)) {
                    peopleMask[i] |= (1 << skillToBit[skill]);
                }
            }
        }
        
        int targetMask = (1 << n) - 1;  // ทักษะทั้งหมดที่ต้องการ 11..1
        
        // dp[mask] = คนน้อยที่สุดที่จะได้ mask นี้
        vector<int> dp(1 << n, INT_MAX / 2);
        // parent[mask] = ไว้คิดย้อนกลับหาคนที่เลือก
        // จาก prev_mask ก่อนหน้าต้องเลือกคนไหนได้เป็น mask ปัจจุบัน
        vector<pair<int, int>> parent(1 << n, {-1, -1});
        
        dp[0] = 0;  // ไม่มีทักษะ = ใช้ 0 คน
        
        for (int i = 0; i < m; i++) {
            int personMask = peopleMask[i];
            if (personMask == 0) continue;  // คนนี้ไม่มีทักษะที่ต้องการ
            
            // คิดทุกกรณีจากบนลงล่างเพื่อหากรณีที่ดีที่สุดและไม่เลือกคนซ้ำ
            for (int mask = targetMask; mask >= 0; mask--) {
                // dp[mask | peopleMask[i]] = min(dp[mask] + 1)
                if (dp[mask] + 1 < dp[mask | personMask]) {
                    dp[mask | personMask] = dp[mask] + 1;
                    parent[mask | personMask] = {mask, i};
                }
            }
        }
        
        // คิดย้อนกลับหาคนที่เลือก
        vector<int> result;
        int mask = targetMask;
        
        while (mask > 0) {
            int personIdx = parent[mask].second;
            result.push_back(personIdx);
            mask = parent[mask].first;
        }
        
        return result;
    }
};