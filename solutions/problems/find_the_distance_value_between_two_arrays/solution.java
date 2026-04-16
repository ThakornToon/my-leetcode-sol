class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        Arrays.sort(arr2);
        int count = 0;
        
        for (int x : arr1) {
            int pos = Arrays.binarySearch(arr2, x);
            if (pos < 0) {
                pos = -pos - 1;  // insertion point
            }
            
            boolean valid = true;
            
            // ตรวจสอบตัวที่ตำแหน่ง pos
            if (pos < arr2.length && Math.abs(arr2[pos] - x) <= d) {
                valid = false;
            }
            
            // ตรวจสอบตัวที่ตำแหน่ง pos-1
            if (pos - 1 >= 0 && Math.abs(arr2[pos - 1] - x) <= d) {
                valid = false;
            }
            
            if (valid) count++;
        }
        
        return count;
    }
}