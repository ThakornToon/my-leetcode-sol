class Solution {
public:
    string reformatDate(string date) {
         // แยก components
        stringstream ss(date);
        string day, month, year;
        ss >> day >> month >> year;
        
        // ตัด suffix ออกจาก day
        int d = stoi(day.substr(0, day.size() - 2));
        
        // month mapping
        unordered_map<string, string> monthMap = {
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
            {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
            {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
        };
        
        // format
        return year + "-" + monthMap[month] + "-" + (d < 10 ? "0" + to_string(d) : to_string(d));
    }
};