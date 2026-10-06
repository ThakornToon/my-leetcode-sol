class MyCalendarThree {
private:
    map<int, int> timeline;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        timeline[startTime]++;
        timeline[endTime]--;
        
        int ongoing = 0;
        int max_k = 0;
        for (auto& pair : timeline) {
            ongoing += pair.second;
            max_k = std::max(max_k, ongoing);
        }
        return max_k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */