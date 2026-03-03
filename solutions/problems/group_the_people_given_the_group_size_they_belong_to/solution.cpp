class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> groups;  // size -> list of people
        
        for (int i = 0; i < groupSizes.size(); i++) {
            int size = groupSizes[i];
            
            // เพิ่มคนเข้า groups ตามขนาด
            groups[size].push_back(i);
            
            // ถ้ามีคนครบตามขนาดกลุ่มแล้ว
            if (groups[size].size() == size) {
                result.push_back(groups[size]);
                groups[size].clear();  // รีเซ็ตสำหรับกลุ่มถัดไป
            }
        }
        
        return result;
    }
};