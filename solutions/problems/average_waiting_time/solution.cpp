class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long currentTime = 0;  // เวลา ณ ปัจจุบัน
        long long totalWait = 0;
        
        for (auto& customer : customers) {
            int arrival = customer[0];
            int time = customer[1];
            
            // เวลาเริ่มทำ order ใหม่
            long long startTime = max(currentTime, (long long)arrival);
            // เวลาทำ order ใหม่เสร็จ
            long long finishTime = startTime + time;

            totalWait += finishTime - arrival;
            currentTime = finishTime;
        }
        
        return (double)totalWait / customers.size();
    }
};