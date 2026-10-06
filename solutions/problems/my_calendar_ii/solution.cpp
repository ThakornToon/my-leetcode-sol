class MyCalendarTwo {
private:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlaps;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        // 1. ตรวจสอบว่าทับซ้อนกับช่วงที่ซ้อนกันอยู่แล้วหรือไม่ (ป้องกัน Triple Booking)
        for (auto& p : overlaps) {
            if (std::max(startTime, p.first) < std::min(endTime, p.second)) {
                return false;
            }
        }
        
        // 2. คำนวณส่วนที่ทับซ้อนกับการจองเดิม แล้วเก็บเข้า overlaps
        for (const auto& p : bookings) {
            int max_s = std::max(startTime, p.first);
            int min_e = std::min(endTime, p.second);
            if (max_s < min_e) {
                overlaps.push_back({max_s, min_e});
            }
        }
        
        // 3. บันทึกการจองใหม่
        bookings.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */