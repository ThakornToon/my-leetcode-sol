class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        sort(nums.begin(), nums.end());
        int count = 0;
        
        // Fix ด้านที่ใหญ่ที่สุด
        for (int c = n - 1; c >= 2; c--) {
            int a = 0;
            int b = c - 1;
            
            while (a < b) {
                if (nums[a] + nums[b] > nums[c]) {
                    // ทุกค่าระหว่าง a ถึง b-1 ใช้ได้กับ b นี้
                    count += (b - a);
                    b--;
                } else {
                    a++;
                }
            }
        }
        
        return count;
    }
};