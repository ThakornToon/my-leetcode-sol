class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
    
        // แปลงเวลาทั้งหมดเป็นนาที
        for (const string& time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            minutes.push_back((hour * 60) + minute);
        }
        
        // เรียงลำดับเวลา
        sort(minutes.begin(), minutes.end());
        
        int minDiff = INT_MAX;
        int n = minutes.size();
        
        // คำนวณความแตกต่างระหว่างเวลาที่ติดกัน
        for (int i = 1; i < n; ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i-1]);
        }
        
        // ตรวจสอบความแตกต่างระหว่างเวลาสุดท้ายและเวลาต้น (การวนรอบ)
        minDiff = min(minDiff, 1440 + minutes[0] - minutes.back());
        
        return minDiff;
    }
};