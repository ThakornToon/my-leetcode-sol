class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);
        
        // นับจำนวนตัวที่น้อยกว่าและเท่ากับ pivot
        int lessCount = 0;
        int equalCount = 0;
        
        for (int num : nums) {
            if (num < pivot) lessCount++;
            else if (num == pivot) equalCount++;
        }
        
        // กำหนดตำแหน่งเริ่มต้นของแต่ละกลุ่ม
        int lessPos = 0;
        int equalPos = lessCount;
        int greaterPos = lessCount + equalCount;
        
        // เติมค่าใน result
        for (int num : nums) {
            if (num < pivot) {
                result[lessPos++] = num;
            } else if (num == pivot) {
                result[equalPos++] = num;
            } else {
                result[greaterPos++] = num;
            }
        }
        
        return result;
    }
};