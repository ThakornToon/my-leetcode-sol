class Solution {
private:
    int dayOfYear(std::string date) {
        vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int total_days = day;
        for (int i = 0; i < month - 1; ++i) {
            total_days += days_in_months[i];
        }
        return total_days;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arrive_overlap = max(dayOfYear(arriveAlice), dayOfYear(arriveBob));
        int leave_overlap = min(dayOfYear(leaveAlice), dayOfYear(leaveBob));
        
        if (arrive_overlap <= leave_overlap) {
            return leave_overlap - arrive_overlap + 1;
        }
        return 0;
    }
};