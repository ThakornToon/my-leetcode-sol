class Solution {
private:
    // แปลงเวลา HH:MM เป็นนาที
    int toMinutes(const string& time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
    }
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> userTimes;
        
        // จัดกลุ่มเวลาตามชื่อ
        for (int i = 0; i < keyName.size(); i++) {
            userTimes[keyName[i]].push_back(toMinutes(keyTime[i]));
        }
        
        vector<string> result;
        
        // ตรวจสอบพนักงานแต่ละคน
        for (auto& [name, times] : userTimes) {
            if (times.size() < 3) continue;
            
            // เรียงลำดับเวลา
            sort(times.begin(), times.end());
            
            // ตรวจสอบ sliding window
            for (int i = 0; i + 2 < times.size(); i++) {
                if (times[i + 2] - times[i] <= 60) {
                    result.push_back(name);
                    break;
                }
            }
        }
        
        // เรียงลำดับผลลัพธ์ตามชื่อ
        sort(result.begin(), result.end());
        return result;
    }
};