class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> s;
        
        // วนลูป 2 เท่าของขนาดอาร์เรย์เพื่อจัดการ circular array
        for (int i = 0; i < 2 * n; i++) {
            int current_idx = i % n;
            
            // ตรวจสอบค่าที่มากกว่าสำหรับองค์ประกอบใน stack
            while (!s.empty() && nums[current_idx] > nums[s.top()]) {
                result[s.top()] = nums[current_idx];
                s.pop();
            }
            
            // เพิ่ม index เฉพาะในรอบแรกเท่านั้น
            if (i < n) {
                s.push(current_idx);
            }
        }
        
        return result;
    }
};