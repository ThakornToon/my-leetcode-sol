class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);  // dp[i] = คะแนนสูงสุดที่ถึง index i
        deque<int> dq;  // เก็บ index ที่มี dp value มากที่สุด
        
        dp[0] = nums[0];
        dq.push_back(0);
        
        for (int i = 1; i < n; i++) {
            // ลบ index ที่อยู่นอกช่วง [i-k, i-1]
            while (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }
            
            // dp[i] = nums[i] + dp[index ที่มีค่ามากสุดใน deque (ช่วง [i-k, i-1])]
            dp[i] = nums[i] + dp[dq.front()];
            
            // รักษา deque ให้เรียงตามค่า dp จากมากไปน้อย
            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        return dp[n - 1];
    }
};