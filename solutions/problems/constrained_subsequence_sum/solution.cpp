class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq;
        int result = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            // หาค่า max จาก deque (ถ้ามี)
            int maxPrev = dq.empty() ? 0 : dp[dq.front()];
            
            // dp[i] = nums[i] + max(0, maxPrev)
            dp[i] = nums[i] + max(maxPrev, 0);
            
            // อัปเดตผลลัพธ์
            result = max(result, dp[i]);
            
            // ลบ indices ที่อยู่นอกช่วง window
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            // ลบ indices ที่มีค่าน้อยกว่า dp[i] (รักษา deque ให้ลดหลั่น)
            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }
            
            // เพิ่ม index ปัจจุบัน
            dq.push_back(i);
        }
        
        return result;
    }
};