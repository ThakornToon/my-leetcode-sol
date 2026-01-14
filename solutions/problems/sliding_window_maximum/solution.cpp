class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;  // เก็บ index ของ nums
        
        for (int i = 0; i < nums.size(); i++) {
            // Step 1: ลบ index ที่อยู่นอกหน้าต่างจากด้านหน้า
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // Step 2: ลบ elements จากด้านหลังที่น้อยกว่า nums[i]
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            // Step 3: เพิ่ม index ปัจจุบัน
            dq.push_back(i);
            
            // Step 4: บันทึกค่าสูงสุดเมื่อผ่านหน้าต่างแรกแล้ว
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};