class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        
        // คำนวณ total sum ของ array ทั้งหมด
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int leftSum = 0;
        int rightSum = totalSum;
        
        for (int i = 0; i < n; i++) {
            // ปรับ rightSum: ลบค่าปัจจุบันออก (เพราะ index i ไม่รวมใน right)
            rightSum -= nums[i];
            
            // คำนวณผลต่าง
            answer[i] = abs(leftSum - rightSum);
            
            // ปรับ leftSum: เพิ่มค่าปัจจุบันสำหรับ iteration ถัดไป
            leftSum += nums[i];
        }
        
        return answer;
    }
};