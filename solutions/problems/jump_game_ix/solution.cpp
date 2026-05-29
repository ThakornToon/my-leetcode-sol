class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        
        // stack เก็บ Component: (max_val, min_val, start_index)
        struct Comp {
            int maxVal, minVal, start;
        };
        stack<Comp> st;
        
        // โดดไปข้างหน้าให้น้อยลง โดดถอยหลังให้มากขึ้น
        // [333 22 3 2 4 1]
        // st = [(3, 3, 0), (3, 3, 1), (3, 3, 2)], i=0,1,2
        // st = [(3, 3, 0), (3, 3, 1), (3, 2, 2)], i=3,4
        // st = [(3, 3, 0), (3, 3, 1), (3, 2, 2), (3, 3, 5)], i=5
        // st = [(3, 3, 0), (3, 3, 1), (3, 2, 2), (3, 2, 5)], i=6
        // st = [(3, 3, 0), (3, 3, 1), (3, 2, 2), (3, 2, 5), (4, 4, 7)], i=7

        // st = [(3, 3, 0), (3, 3, 1), (3, 2, 2), (3, 2, 5), (4, 1, 7)], i=8
        // st = [(3, 3, 0), (3, 3, 1), (3, 2, 2), (4, 1, 5)]
        // st = [(4, 1, 0)]
        // 2 โดดถอยไป 3 ได้
        // 3 โดดขึ้นไป 2 ได้
        // 1 โดดถอยไป 4 ได้
        // 4 โดดขึ้นไป 1 ได้

        // 3 - 3 - 3,2 - 3,2 - 4,1
        // 4,1 สามารถไปกลับกับ 3,2 ได้
        // 3 - 3 - 3,2 - 4,1
        // ทุกตัวสามารถมาที่ 4,1 ได้

        // [333 22 3 2 4]
        // st = [(3, 3, 0), (3, 3, 1), (3, 2, 2), (3, 2, 5), (4, 4, 7)]
        //  3 - 3 - 3,2 - 3,2 - 4
        // ไม่สามารถเชื่อมกันได้แล้วทุกกลุ่มในช่วงนั้นจะใช้คำตอบร่วมกัน

        for (int i = 0; i < n; i++) {
            Comp curr = {nums[i], nums[i], i};
            
            // รวมกับ component ทางซ้ายเรื่อยๆ
            // เงื่อนไข: ค่าต่ำสุดของ component ขวา (curr.minVal) < ค่าสูงสุดของ component ซ้าย (st.top().maxVal)
            // พิจารณาการโดดจาก comp ซ้ายไปขวา (ใช้ maxVal ตอบร่วมกันได้)
            while (!st.empty() && curr.minVal < st.top().maxVal) {
                curr.maxVal = max(curr.maxVal, st.top().maxVal);
                curr.minVal = min(curr.minVal, st.top().minVal);
                curr.start = st.top().start;
                st.pop();
            }
            st.push(curr);
        }
        
        // เตรียม answer array
        vector<int> ans(n);
        
        // stack ตอนนี้มี components เรียงจากซ้ายไปขวา
        // แต่ละ component มี start index และ maxVal
        vector<Comp> comps;
        while (!st.empty()) {
            comps.push_back(st.top());
            st.pop();
        }
        reverse(comps.begin(), comps.end());
        
        // ตอนนี้ comps เรียงจากซ้ายไปขวา
        // กำหนด end index ให้แต่ละ component
        for (int i = 0; i < comps.size(); i++) {
            int end = (i + 1 < comps.size()) ? comps[i + 1].start - 1 : n - 1;
            for (int j = comps[i].start; j <= end; j++) {
                ans[j] = comps[i].maxVal;
            }
        }
        
        return ans;
    }
};