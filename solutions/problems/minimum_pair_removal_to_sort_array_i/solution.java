class Solution {
    public int minimumPairRemoval(int[] nums) {
        int n = nums.length;
        
        // ตรวจสอบ non-decreasing
        boolean nonDecreasing = true;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                nonDecreasing = false;
                break;
            }
        }
        if (nonDecreasing) return 0;
        
        // ใช้ List เพื่อจัดการการลบ element
        List<Integer> list = new ArrayList<>();
        for (int num : nums) {
            list.add(num);
        }
        
        int operations = 0;
        
        while (true) {
            // หาคู่ที่มี sum ต่ำสุด
            int minSum = Integer.MAX_VALUE;
            int minIndex = -1;
            
            for (int i = 0; i < list.size() - 1; i++) {
                int sum = list.get(i) + list.get(i + 1);
                if (sum < minSum) {
                    minSum = sum;
                    minIndex = i;
                }
            }
            
            // Merge
            list.set(minIndex, minSum);
            list.remove(minIndex + 1);
            operations++;
            
            // ตรวจสอบ non-decreasing
            boolean isNonDecreasing = true;
            for (int i = 0; i < list.size() - 1; i++) {
                if (list.get(i) > list.get(i + 1)) {
                    isNonDecreasing = false;
                    break;
                }
            }
            
            if (isNonDecreasing) {
                break;
            }
        }
        
        return operations;
    }
}