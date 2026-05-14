class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        // {perfixSum at i : i}
        unordered_map<int, int> prefixMap;
        int count = 0;
        int prefixSum = 0;
        int lastEnd = -1;
        
        prefixMap[0] = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            
            // ตรวจสอบว่ามี prevPrefixSum = prefixSum - target ไหม
            if (prefixMap.count(prefixSum - target)) {
                int prev = prefixMap[prefixSum - target];  // index prevPrefixSum ตำแหน่งเริ่มต้น subarray

                count++;
                lastEnd = i;
                
                // รีเซ็ต map สำหรับ segment ใหม่
                prefixMap.clear();
                prefixMap[0] = i;  // เริ่ม segment ใหม่ที่ตำแหน่ง i
                prefixSum = 0;
            }
            
            prefixMap[prefixSum] = i;
        }
        
        return count;
    }
};