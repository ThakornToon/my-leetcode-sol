class RangeModule {
private:
    set<pair<int, int>> intervals;

public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        // หาช่วง {l, r} แรกที่ l > left โดยไม่สนใจค่า r 
        auto it = intervals.upper_bound({left, INT_MAX});
        if (it != intervals.begin()) {
            auto prev = std::prev(it);  // ย้อนไปดูช่วงก่อนหน้า

            // รวมช่วงที่อยู่ข้างหน้า left ซึ่งมีอันเดียว
            if (prev->second >= left) {
                it = prev;
                left = std::min(left, prev->first);
                right = std::max(right, prev->second);
            }
        }

        // ไล่ดูช่วงทางขวาไปเรื่อยๆ
        while (it != intervals.end() && it->first <= right) {
            right = std::max(right, it->second);
            it = intervals.erase(it);  // คืน iterator ตัวที่อยู่ถัดจากตัวที่ลบไป
        }

        intervals.insert({left, right});
    }
    
    bool queryRange(int left, int right) {
        // หา {l, r} ตัวแรกที่ l > left
        auto it = intervals.upper_bound({left, INT_MAX});
        if (it == intervals.begin()) return false;

        // ถอยมาหาช่วงก่อนหน้าที่อาจครอบคลุม {l, r}
        --it;
        return it->first <= left && right <= it->second;
    }
    
    void removeRange(int left, int right) {
        // หา {l, r} ตัวแรกที่ l > left
        auto it = intervals.upper_bound({left, INT_MAX});

        if (it != intervals.begin()) {
            // ถอยมาช่วงก่อนหน้าที่ {l, r} สุดท้ายโดย l <= left
            auto prev = std::prev(it);
            // ถ้าทับซ้อนกัน
            if (prev->second > left) {
                it = prev;
                int p_start = prev->first;
                int p_end = prev->second;
                it = intervals.erase(prev);
                if (p_start < left) {
                    intervals.insert({p_start, left});
                }
                if (p_end > right) {
                    intervals.insert({right, p_end});
                }
            }
        }

        // ไล่คิด cadidate ต่อไปเรื่อยๆ
        while (it != intervals.end() && it->first < right) {
            int p_start = it->first;
            int p_end = it->second;
            it = intervals.erase(it);
            if (p_end > right) {
                intervals.insert({right, p_end});
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */