class Solution {
private:
    int atMostK(vector<int>& nums, int k) {  
        int left = 0;
        int oddCount = 0;
        int result = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            // เพิ่ม oddCount ถ้าเป็นเลขคี่
            oddCount += nums[right] % 2;
            
            // ถ้า oddCount > k, ขยับ left
            while (oddCount > k && left <= right) {
                oddCount -= nums[left] % 2;
                left++;
            }
            
            // จำนวน subarrays ที่ลงท้ายที่ right
            // และมีเลขคี่ ≤ k
            result += (right - left + 1);
        }
        
        return result;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // exactly K = atMost(K) - atMost(K-1)
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};