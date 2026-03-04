class Solution {
    public int findBestValue(int[] arr, int target) {
        // sort array
        Arrays.sort(arr);
        int n = arr.length;
        
        // prefix sum
        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        
        int left = 0;
        int right = arr[n - 1];
        int bestValue = 0;
        int minDiff = Integer.MAX_VALUE;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // binary search หาตำแหน่งแรกที่ > mid
            int pos = findFirstGreater(arr, mid);
            
            // คำนวณ sum
            int sum = prefix[pos] + (n - pos) * mid;
            int diff = Math.abs(sum - target);
            
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
    
    private int findFirstGreater(int[] arr, int value) {
        int left = 0;
        int right = arr.length - 1;
        int result = arr.length;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > value) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
}