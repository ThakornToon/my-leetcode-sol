class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // คำนวณผลรวมของการหารด้วย mid
            long long sum = 0;
            for (int num : nums) {
                // การหารแบบปัดเศษขึ้น
                sum += (num + mid - 1) / mid;
            }
            
            if (sum <= threshold) {
                // ถ้าผลรวม <= threshold ลอง divisor ที่น้อยลง
                result = mid;
                right = mid - 1;
            } else {
                // ถ้าผลรวม > threshold ต้องใช้ divisor ที่มากขึ้น
                left = mid + 1;
            }
        }
        
        return result;
    }
};