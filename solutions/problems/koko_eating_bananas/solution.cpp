class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // คำนวณเวลาที่ใช้กับ speed = mid
            int hours = 0;
            for (int pile : piles) {
                // hours += ceil((double)pile / mid); ปัดขึ้น
                hours += (pile + mid - 1) / mid;  // เทียบเท่ากับ ceil
            }
            
            if (hours <= h) {
                // ใช้เวลาน้อยกว่า h → ลอง k ที่น้อยลง
                high = mid;
            } else {
                // ใช้เวลามากกว่า h → ต้องเร็วขึ้น
                low = mid + 1;
            }
        }
        
        return high;
    }
};