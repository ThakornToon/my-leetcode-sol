class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> modMap;
        modMap[0] = 1; // prefix sum ว่าง
        
        int prefixSum = 0;
        int count = 0;
        
        for (int num : nums) {
            prefixSum += num;
            
            int remainder = prefixSum % k;
            if (remainder < 0) {
                remainder += k;
            }
            
            if (modMap.find(remainder) != modMap.end()) {
                count += modMap[remainder];
            }
            
            modMap[remainder]++;
        }
        
        return count;
    }
};