class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> starts; // เก็บจุดเริ่มต้นและ index ของจุเริ่มต้นนั้นที่อยู่ในอาเรย์เดิม
        for (int i = 0; i < intervals.size(); i++) {
            starts.emplace_back(intervals[i][0], i);
        }
        sort(starts.begin(), starts.end()); // เรียงตามจุดเริ่มต้น
        
        vector<int> res;
        for (auto& interval : intervals) {
            int end = interval[1];
            auto it = lower_bound(starts.begin(), starts.end(), make_pair(end, 0)); // make_pair(end, 0): ค่าที่ต้องการค้นหา (สร้างเป็น pair โดยใช้ end ของช่วงปัจจุบันและ 0 เป็น index) โดยสนใจแค่ค่า end
            if (it != starts.end()) {
                res.push_back(it->second); // ใช้ original_index
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};