class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size();
        int missingCount;

        while (left < right) {
            int mid = left + (right - left) / 2;
            missingCount = arr[mid] - (mid + 1);
            
            if (missingCount < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        // left คือ index แรกที่ missingCount >= k

        // กรณีที่คำตอบอยู่หลังตัวสุดท้าย
        if (left == arr.size()) {
            missingCount = arr.back() - arr.size();
            return arr.back() + (k - missingCount);
            // หรือ arr.size() + k;
        }

        missingCount = arr[left] - (left + 1);
        return arr[left] - (missingCount - k + 1);
    }
};