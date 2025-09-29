class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<int> stk;  // เก็บ function_id
        int prevTime = 0;
        
        for (const string& log : logs) {
            // Parse log
            int pos1 = log.find(':');
            int pos2 = log.find(':', pos1 + 1);
            
            int id = stoi(log.substr(0, pos1));
            string type = log.substr(pos1 + 1, pos2 - pos1 - 1);
            int timestamp = stoi(log.substr(pos2 + 1));
            
            if (type == "start") {
                if (!stk.empty()) {
                    // Function ก่อนหน้าถูก interrupt, บันทึกเวลาจนถึงตอนนี้
                    result[stk.top()] += timestamp - prevTime;
                }
                stk.push(id);
                prevTime = timestamp;
            } else { // "end"
                result[stk.top()] += timestamp - prevTime + 1;
                stk.pop();
                prevTime = timestamp + 1;  // timestamp ต่อไปเริ่มจาก +1
            }
        }
        
        return result;
    }
};