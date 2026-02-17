class Solution {
    public int maxSumDivThree(int[] nums) {
        PriorityQueue<Integer> pq1 = new PriorityQueue<>();
        PriorityQueue<Integer> pq2 = new PriorityQueue<>();
        
        int sum = 0;
        for (int num : nums) {
            sum += num;
            if (num % 3 == 1) {
                pq1.offer(num);
            } else if (num % 3 == 2) {
                pq2.offer(num);
            }
        }
        
        int remainder = sum % 3;
        if (remainder == 0) {
            return sum;
        }
        
        int result = 0;
        
        if (remainder == 1) {
            // ลบ 1 ตัวจาก pq1 หรือ 2 ตัวจาก pq2
            if (!pq1.isEmpty()) {
                result = Math.max(result, sum - pq1.peek());
            }
            if (pq2.size() >= 2) {
                int first = pq2.poll();
                int second = pq2.poll();
                result = Math.max(result, sum - first - second);
            }
        } else { // remainder == 2
            // ลบ 1 ตัวจาก pq2 หรือ 2 ตัวจาก pq1
            if (!pq2.isEmpty()) {
                result = Math.max(result, sum - pq2.peek());
            }
            if (pq1.size() >= 2) {
                int first = pq1.poll();
                int second = pq1.poll();
                result = Math.max(result, sum - first - second);
            }
        }
        
        return result;
    }
}