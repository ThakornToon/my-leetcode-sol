class Solution {
    public int findLucky(int[] arr) {
        Arrays.sort(arr);
        
        int maxLucky = -1;
        int i = 0;
        int n = arr.length;
        
        while (i < n) {
            int val = arr[i];
            int count = 0;
            
            while (i < n && arr[i] == val) {
                count++;
                i++;
            }
            
            if (count == val && val > maxLucky) {
                maxLucky = val;
            }
        }
        
        return maxLucky;
    }
}