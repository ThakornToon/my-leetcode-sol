class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> index_map;
        for (int i = 0; i < list1.size(); ++i) {
            index_map[list1[i]] = i;
        }

        vector<string> result;
        int min_sum = INT_MAX;

        for (int j = 0; j < list2.size(); ++j) {
            // ดัชนี j เกินผลรวมต่ำสุดที่มีอยู่แล้ว ไม่มีทางได้ค่าน้อยกว่าเดิม
            if (j > min_sum) break;

            auto it = index_map.find(list2[j]);
            if (it != index_map.end()) {
                int sum = it->second + j;
                if (sum < min_sum) {
                    min_sum = sum;
                    result.clear();
                    result.push_back(list2[j]);
                } else if (sum == min_sum) {
                    result.push_back(list2[j]);
                }
            }
        }

        return result;
    }
};