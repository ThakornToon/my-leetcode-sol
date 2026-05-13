class Solution {
    public int minMoves(int[] nums, int limit) {
        int n = nums.length;
        int[] diff = new int[2 * limit + 2]; // diff array สำหรับ range
        
        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            if (a > b) {
                int temp = a;
                a = b;
                b = temp;
            }
            
            int sum = a + b;
            
            // Case 1: ทุก target เริ่มต้นต้องเปลี่ยน 2 ครั้ง
            // ช่วง [2, 2*limit]
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;
            
            // Case 2: target ที่เปลี่ยนได้ 1 ครั้ง → ลด 1
            // ช่วง [a+1, b+limit]
            diff[a + 1] -= 1;
            diff[b + limit + 1] += 1;
            
            // Case 3: target = sum (เปลี่ยน 0 ครั้ง) → ลดอีก 1
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }
        
        // prefix sum เพื่อหาค่าจริง
        int answer = n;
        int curr = 0;
        for (int target = 2; target <= 2 * limit; target++) {
            curr += diff[target];
            answer = Math.min(answer, curr);
        }
        
        return answer;
    }
}