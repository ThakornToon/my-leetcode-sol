class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
int left = 1;
        int right = getMax(nums);
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // คำนวณผลรวมของการหารด้วย mid
            long sum = calculateSum(nums, mid);
            
            if (sum <= threshold) {
                // ถ้าผลรวม <= threshold ลอง divisor ที่น้อยลง
                result = mid;
                right = mid - 1;
            } else {
                // ถ้าผลรวม > threshold ต้องใช้ divisor ที่มากขึ้น
                left = mid + 1;
            }
        }
        
        return result;
    }
    
    private int getMax(int[] nums) {
        int max = nums[0];
        for (int num : nums) {
            max = Math.max(max, num);
        }
        return max;
    }
    
    private long calculateSum(int[] nums, int divisor) {
        long sum = 0;
        for (int num : nums) {
            // การหารแบบปัดเศษขึ้น
            sum += (num + divisor - 1) / divisor;
        }
        return sum;
    }
}