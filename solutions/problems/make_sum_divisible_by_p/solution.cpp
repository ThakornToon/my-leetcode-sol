class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // คำนวณผลรวมทั้งหมด
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int target = totalSum % p;
        if (target == 0) return 0;
        
        // ใช้ hash map เก็บ remainder และ index ล่าสุด
        unordered_map<int, int> lastSeen;
        lastSeen[0] = -1; // remainder 0 ที่ index -1
        
        int minLen = nums.size();
        long long prefixSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int currRemainder = prefixSum % p;
            
            // หาค่า remainder ที่ต้องการ: (currRemainder - target + p) % p
            // เศษของทั้งหมด(ต้องการเอาออก) = เศษของช่วงที่เอาออก (end - start + p) % p
            int need = (currRemainder - target + p) % p;
            
            // ใช้ที่สั้นที่สุด
            if (lastSeen.count(need)) {
                int len = i - lastSeen[need];
                if (len < minLen) {
                    minLen = len;
                }
            }
            
            lastSeen[currRemainder] = i;
        }
        
        return minLen == nums.size() ? -1 : minLen;
    }
};