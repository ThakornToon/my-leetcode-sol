class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        
        // สร้าง prefix sum
        int[] prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        int minLen = n + 1;
        
        // ลองทุก start index
        for (int i = 0; i < n; i++) {
            int targetSum = target + prefixSum[i];
            int j = binarySearch(prefixSum, targetSum);
            
            if (j != -1) {
                minLen = Math.min(minLen, j - i);
            }
        }
        
        return (minLen == n + 1) ? 0 : minLen;
    }
    
    private int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
}