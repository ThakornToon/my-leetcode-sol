class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        sort(nums.begin(), nums.end());
        
        int maxLength = 0;
        int j = 0;  // pointer สำหรับขยาย
        
        for (int i = 0; i < n; i++) {
            // ขยาย j ตราบใดที่ตรงเงื่อนไข
            while (j < n && nums[j] <= (long long)k * nums[i]) {
                j++;
            }
            
            // ความยาวช่วงที่เริ่มที่ i
            maxLength = max(maxLength, j - i);
            
            // เมื่อ i ขยับ, j อาจอยู่ที่เดิมหรือขยับด้วย
        }
        
        return n - maxLength;
    }
};