class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        
        // สร้าง prefix sums
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        deque<int> dq;
        int minLength = INT_MAX;
        
        for (int i = 0; i <= n; i++) {
            // ตรวจสอบจากด้านหน้า
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                minLength = min(minLength, i - dq.front());
                dq.pop_front();
            }
            
            // ลบ index ที่ทำให้ prefix[current] <= prefix[back]
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }
            
            // เพิ่ม current index
            dq.push_back(i);
        }
        
        return minLength == INT_MAX ? -1 : minLength;
    }
};