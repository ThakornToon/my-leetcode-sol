class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
        int maxDist = 0;
        
        for (int i = 0; i < nums1.length; i++) {
            int left = i;
            int right = nums2.length - 1;
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
            
            if (j != -1 && j >= i) {
                maxDist = Math.max(maxDist, j - i);
            }
        }
        
        return maxDist;
    }
}