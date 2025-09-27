class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1; // prefix sum = 0 ที่ index -1
        
        int maxLen = 0;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // แปลง 0 เป็น -1, 1 เป็น 1
            sum += (nums[i] == 0) ? -1 : 1;
            
            if (prefixMap.find(sum) != prefixMap.end()) {
                // พบ prefix sum ซ้ำ → คำนวณความยาว
                maxLen = max(maxLen, i - prefixMap[sum]);
            } else {
                // เก็บตำแหน่งแรกของ prefix sum นี้
                prefixMap[sum] = i;
            }
        }
        
        return maxLen;
    }
};