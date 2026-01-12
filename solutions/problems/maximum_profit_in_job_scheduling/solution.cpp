class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        // สร้าง jobs และเรียงตาม endTime
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        
        // map<เวลาสิ้นสุด, กำไรสูงสุด>
        map<int, int> dp;
        dp[0] = 0; // base case
        
        for (auto& job : jobs) {
            int end = job[0], start = job[1], profit = job[2];
            
            // หางานที่สิ้นสุดก่อน start (ใช้ upper_bound - 1)
            auto it = dp.upper_bound(start); // > start
            it--; // ≤ start
            
            int currProfit = it->second + profit;
            
            // เปรียบเทียบกับค่าที่ดีที่สุดในปัจจุบัน
            auto lastIt = dp.end();
            lastIt--;
            int maxProfitSoFar = lastIt->second;
            
            if (currProfit > maxProfitSoFar) {
                dp[end] = currProfit;
            }
        }
        
        return dp.rbegin()->second;
    }
};