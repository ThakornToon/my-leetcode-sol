class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min heap เรียงน้อยไปมากเก็บโครงสร้าง {val, row_idx, col_idx}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap; 

        int max_val = INT_MIN;
        int k = nums.size();
        // ใส่ค่าน้อยสุดของทุก list และแนบตำแหน่งไป
        for (int i = 0; i < k; ++i) {
            min_heap.push({nums[i][0], i, 0});
            max_val = std::max(max_val, nums[i][0]);  // ขอบบนของช่วงค่าใน min heap
        }

        int range_start = 0, range_end = INT_MAX;  // คำตอบที่จะตอบ

        while (true) {
            // ค่าน้อยสุดของทุก list ที่กำลังพิจารณาเป็นขอบล่าง
            auto curr = min_heap.top();
            min_heap.pop();
            int min_val = curr[0];
            int r = curr[1];
            int c = curr[2];

            // หาช่วงที่ดีสุด
            if (max_val - min_val < range_end - range_start) {
                range_start = min_val;
                range_end = max_val;
            }

            // หากถึงสมาชิกตัวสุดท้ายของลิสต์ใดลิสต์หนึ่งแล้ว จะไม่สามารถครอบคลุมครบทุกกลุ่มได้อีก
            if (c + 1 == nums[r].size()) {
                break;
            }

            // ขยับขอบเขตเลื่อนโดยเอาค่าน้อยสุดใน min heap (curr) ออกแล้วใส่ค่าถัดไปใน list เดียวกันไปพิจารณาต่อ
            int next_val = nums[r][c + 1];
            min_heap.push({next_val, r, c + 1});
            max_val = std::max(max_val, next_val);
        }

        return {range_start, range_end};
    }
};