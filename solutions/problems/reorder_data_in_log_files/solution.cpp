class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLogs;
        vector<string> digitLogs;
        
        // แยก logs
        for (const string& log : logs) {
            // หาตำแหน่ง space แรก
            size_t spacePos = log.find(' ');
            
            // ตรวจสอบตัวอักษรถัดจาก space แรกว่าเป็นตัวเลขหรือไม่
            if (isdigit(log[spacePos + 1])) {
                digitLogs.push_back(log);
            } else {
                letterLogs.push_back(log);
            }
        }
        
        // Sort letter logs
        sort(letterLogs.begin(), letterLogs.end(), [](const string& a, const string& b) {
            // หา content (ส่วนหลัง space แรก)
            size_t spaceA = a.find(' ');
            size_t spaceB = b.find(' ');
            
            string contentA = a.substr(spaceA + 1);
            string contentB = b.substr(spaceB + 1);
            
            // เปรียบเทียบ content
            if (contentA != contentB) {
                return contentA < contentB;
            }
            
            // ถ้า content เท่ากัน ให้เปรียบเทียบ identifier
            string idA = a.substr(0, spaceA);
            string idB = b.substr(0, spaceB);
            
            return idA < idB;
        });
        
        // รวมผลลัพธ์ (letter logs ก่อน, digit logs หลัง)
        vector<string> result;
        result.insert(result.end(), letterLogs.begin(), letterLogs.end());
        result.insert(result.end(), digitLogs.begin(), digitLogs.end());
        
        return result;
    }
};