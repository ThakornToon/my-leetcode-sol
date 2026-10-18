class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        if (target == "0000") return 0;

        unordered_set<string> visited;
        queue<string> q;

        q.push("0000");
        visited.insert("0000");
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();

                if (curr == target) return steps;

                // ลองหมุนรหัสทั้ง 4 หลัก ขึ้น(+1) และลง(-1)
                for (int j = 0; j < 4; ++j) {
                    for (int d : {-1, 1}) {
                        string next_state = curr;
                        next_state[j] = (next_state[j] - '0' + d + 10) % 10 + '0';

                        if (!dead.count(next_state) && !visited.count(next_state)) {
                            visited.insert(next_state);
                            q.push(next_state);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};