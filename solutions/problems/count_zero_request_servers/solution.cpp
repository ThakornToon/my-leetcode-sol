class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m, 0);
        
        // เรียงลำดับ logs ตามเวลาน้อยไปมาก
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        // จัดเรียง queries เรียงเวลาน้อยไปมากพร้อมเก็บ idx เดิม
        vector<pair<int, int>> sorted_queries(m);
        for (int i = 0; i < m; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());
        
        vector<int> count(n + 1, 0);  // 1-active
        int active_servers = 0;
        int l = 0, r = 0;  // two pointer
        int total_logs = logs.size();
        
        // ประมวลผล queries ด้วย Two Pointers
        for (const auto& [q_time, idx] : sorted_queries) {
            int window_start = q_time - x;
            int window_end = q_time;
            
            // เพิ่ม logs ที่อยู่ในช่วงเวลา [window_start, window_end] เข้ามา
            while (r < total_logs && logs[r][1] <= window_end) {
                int server = logs[r][0];
                if (count[server] == 0) {
                    active_servers++;
                }
                count[server]++;
                r++;
            }
            
            // ตัด logs ที่เก่าเกินกว่า window_start ออก
            while (l < total_logs && logs[l][1] < window_start) {
                int server = logs[l][0];
                count[server]--;
                if (count[server] == 0) {
                    active_servers--;
                }
                l++;
            }
            
            // not active server
            ans[idx] = n - active_servers;
        }
        
        return ans;
    }
};