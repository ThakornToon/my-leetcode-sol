class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0;
        
        for (int i = 0; i < nums1.size(); i++) {
            // binary search หา j ขวาสุดที่ nums2[j] >= nums1[i]
            int left = i, right = nums2.size() - 1;
            int j = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums2[mid] >= nums1[i]) {
                    j = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            if (j != -1) {
                maxDist = max(maxDist, j - i);
            }
        }
        
        return maxDist;
    }
};