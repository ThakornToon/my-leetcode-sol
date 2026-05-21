class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> lastSeen;
        int maxSum = 0;
        int currentSum = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            int num = nums[right];
            
            // ถ้าเจอตัวเลขที่เคยเห็นและอยู่ใน window ปัจจุบัน
            if (lastSeen.find(num) != lastSeen.end() && lastSeen[num] >= left) {
                // ลบค่าทางซ้ายออกจากผลรวม
                for (int i = left; i <= lastSeen[num]; i++) {
                    currentSum -= nums[i];
                }
                left = lastSeen[num] + 1;
            }
            
            // เพิ่มตัวเลขปัจจุบัน
            currentSum += num;
            lastSeen[num] = right;
            
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};