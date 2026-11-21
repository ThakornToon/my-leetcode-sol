class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> orig_child(n);
        for (int i = 1; i < n; ++i) {
            orig_child[parent[i]].push_back(i);
        }

        vector<int> new_parent(n, -1);  // บันทึกการปรับ parent ใหม่
        vector<int> last_anc(26, -1);  // เก็บ y ancestor ของแต่ละตัวอักษร

        // รอบที่ 1: หาพ่อใหม่ของแต่ละโหนดด้วย DFS พร้อม Backtracking
        auto dfs_reparent = [&](auto& self, int x) -> void {
            int c = s[x] - 'a';

            // บันทึกตำแหน่งที่พบในเส้นทาง
            if (last_anc[c] != -1) {
                // กรณีเคยเจอตัวอักษรเดียวกันในเส้นทางปัจจุบันมาก่อนหน้านี้
                new_parent[x] = last_anc[c]; 
            } else {
                // ไม่มี y ancestor ของ x
                new_parent[x] = parent[x];
            }

            int prev_anc = last_anc[c];
            last_anc[c] = x;

            // DFS ไปทุกเส้นทาง
            for (int v : orig_child[x]) {
                self(self, v);
            }

            // backtrack ย้อนเส้นทางขึ้นไปเพื่อคิดเส้นทางอื่น
            last_anc[c] = prev_anc;
        };

        dfs_reparent(dfs_reparent, 0);

        // สร้างต้นไม้ใหม่
        vector<vector<int>> new_child(n);
        for (int i = 1; i < n; ++i) {
            if (new_parent[i] != -1) {
                new_child[new_parent[i]].push_back(i);
            }
        }

        vector<int> ans(n, 1);

        // รอบที่ 2: คำนวณขนาด Subtree ในต้นไม้ใหม่
        auto dfs_size = [&](auto& self, int x) -> int {
            int sz = 1;
            // เอาขนาดลูกทุกอันมารวมกัน
            for (int v : new_child[x]) {
                sz += self(self, v);
            }
            ans[x] = sz;
            return sz;
        };

        dfs_size(dfs_size, 0);
        return ans;
    }
};