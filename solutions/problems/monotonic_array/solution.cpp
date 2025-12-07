class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true, dec = true;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i+1]) {
                dec = false;
            }
            if (nums[i] > nums[i+1]) {
                inc = false;
            }
            
            // Optimization: ถ้าไม่เป็นทั้งคู่แล้ว สามารถ break ได้
            if (!inc && !dec) return false;
        }
        
        return inc || dec;
    }
};