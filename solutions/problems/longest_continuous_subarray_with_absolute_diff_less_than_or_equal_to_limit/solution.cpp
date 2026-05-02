class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxD, minD;
        int left = 0, ans = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            // รักษา deque ให้อยู่ในสภาพ monotonic
            while (!maxD.empty() && nums[maxD.back()] <= nums[right]) maxD.pop_back();  // ตัวหน้ามากสุดเสมอ
            while (!minD.empty() && nums[minD.back()] >= nums[right]) minD.pop_back();  // ตัวหน้าน้อยสุดเสมอ
            maxD.push_back(right);
            minD.push_back(right);
            
            // ละเมิดเงื่อนไข -> ขยับ left
            while (nums[maxD.front()] - nums[minD.front()] > limit) {
                if (maxD.front() == left) maxD.pop_front();
                if (minD.front() == left) minD.pop_front();
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};