class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        // sort array
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        // prefix sum
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
                
        int left = 0;
        int right = arr.back();
        int bestValue = 0;
        int minDiff = INT_MAX;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // binary search หาตำแหน่งแรกที่ > mid
            auto it = upper_bound(arr.begin(), arr.end(), mid);
            int pos = it - arr.begin();
            
            // คำนวณ sum
            int sum = prefix[pos] + (n - pos) * mid;
            int diff = abs(sum - target);
            
            // อัปเดตค่าที่ดีที่สุด
            if (diff < minDiff || (diff == minDiff && mid < bestValue)) {
                minDiff = diff;
                bestValue = mid;
            }
            
            if (sum < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return bestValue;
    }
};