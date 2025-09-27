class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        
        for (int num : nums) {
            // อัปเดตสามค่ามากที่สุด
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num > max3) {
                max3 = num;
            }
            
            // อัปเดตสองค่าน้อยที่สุด
            if (num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }
        
        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};