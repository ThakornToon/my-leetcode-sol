class SummaryRanges {
private:
    map<int, int> intervals;  // {start, end}
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        // {s, e} หา s แรกที่มีค่า > value
        auto itBigger = intervals.upper_bound(value);
        
        int start = value, end = value;
        
        // ตรวจสอบช่วงทางซ้าย
        if (itBigger != intervals.begin()) {
            auto smallerOrEqual = prev(itBigger);
            // ถ้าค่าอยู่ในช่วงซ้ายอยู่แล้ว ไม่ต้องทำอะไร
            if (value <= smallerOrEqual->second) {
                return;
            }
            // ถ้าค่าต่อท้ายช่วงซ้ายพอดี
            if (smallerOrEqual->second + 1 == value) {
                start = smallerOrEqual->first;
            }
        }
        
        // ตรวจสอบช่วงทางขวา
        if (itBigger != intervals.end() && value + 1 == itBigger->first) {
            end = itBigger->second;
            intervals.erase(itBigger);
        }
        
        // หากลบช่วงซ้ายออกหรือต้องการอัปเดต ให้จัดการรวมช่วง
        auto it = intervals.upper_bound(value);
        if (it != intervals.begin()) {
            auto left = prev(it);
            if (left->second + 1 >= start) {
                left->second = std::max(left->second, end);
                return;
            }
        }
        
        // ถ้ารวมกับทางซ้ายได้จะไปปรับ end ของช่วงทางซ้าย, ถ้าไม่เราจะใส่ {s, e} ใหม่ไปหลังจากลบช่วงทางขวา(รวม)
        intervals[start] = end;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto& pair : intervals) {
            res.push_back({pair.first, pair.second});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */