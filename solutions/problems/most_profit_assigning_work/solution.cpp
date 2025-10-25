class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        
        // รวม difficulty และ profit เป็นคู่
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        
        // เรียงตาม difficulty
        sort(jobs.begin(), jobs.end());
        
        // เรียง worker
        sort(worker.begin(), worker.end());
        
        int totalProfit = 0;
        int maxProfit = 0;
        int j = 0;
        
        // สำหรับแต่ละ worker
        for (int i = 0; i < m; i++) {
            // หางานทั้งหมดที่ worker นี้ทำได้ และเก็บกำไรสูงสุด
            while (j < n && jobs[j].first <= worker[i]) {
                maxProfit = max(maxProfit, jobs[j].second);
                j++;
            }
            totalProfit += maxProfit;
        }
        
        return totalProfit;
    }
};