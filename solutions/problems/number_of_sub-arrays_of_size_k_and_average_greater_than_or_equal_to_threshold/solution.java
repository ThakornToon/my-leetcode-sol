class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int targetSum = k * threshold;
        int windowSum = 0;
        int count = 0;
        
        // คำนวณ window แรก
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }
        
        if (windowSum >= targetSum) count++;
        
        // เลื่อน window
        for (int i = k; i < arr.length; i++) {
            windowSum = windowSum - arr[i - k] + arr[i];
            if (windowSum >= targetSum) count++;
        }
        
        return count;
    }
}