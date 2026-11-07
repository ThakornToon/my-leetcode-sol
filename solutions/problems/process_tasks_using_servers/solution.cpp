class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        vector<int> ans(m);

        // free: (weight, index) -> min-heap น้อยไปมาก
        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P>> freeServers;

        // busy: (freeTime, weight, index) -> min-heap น้อยไปมาก
        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> busyServers;

        for (int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        // วนคิดให้ครบทุก task
        long long t = 0;
        for (int i = 0; i < m; i++) {
            t = max(t, (long long)i);  // เวลาปัจจุบัน

            // ปล่อยเซิร์ฟเวอร์ที่ทำงานเสร็จแล้วกลับไปที่ free
            while (!busyServers.empty() && get<0>(busyServers.top()) <= t) {
                auto [ft, w, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({w, idx});
            }

            // ถ้าไม่มีเซิร์ฟเวอร์ว่าง ให้รอจนกว่าจะมีตัวแรกว่าง
            if (freeServers.empty()) {
                t = get<0>(busyServers.top());  // ช้ามเวลาไป ณ จุดที่ว่าง
                while (!busyServers.empty() && get<0>(busyServers.top()) <= t) {
                    auto [ft, w, idx] = busyServers.top();
                    busyServers.pop();
                    freeServers.push({w, idx});
                }
            }

            // Assign งาน
            auto [w, idx] = freeServers.top();
            freeServers.pop();

            ans[i] = idx;
            busyServers.push({t + tasks[i], w, idx});
        }

        return ans;
    }
};