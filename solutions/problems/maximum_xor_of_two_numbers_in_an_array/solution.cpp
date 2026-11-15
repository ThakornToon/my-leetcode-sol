class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_xor = 0;
        int mask = 0;
        
        // พิจารณาบิตทีละตำแหน่ง
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            unordered_set<int> prefixes;
            
            // พิจารณาแค่ตำแหน่งบิตที่ตรงกับ mask prefix
            for (int num : nums) {
                prefixes.insert(num & mask);
            }
            
            // หากเราต้องการให้บิตที่พิจารณาเป็น 1 ใน max_xor
            int tentative = max_xor | (1 << i);
            bool found = false;
            
            // หา p1 ^ p2 = tentative (ดูแค่บิต prefix)
            for (int p : prefixes) {
                if (prefixes.count(p ^ tentative)) {
                    found = true;
                    break;
                }
            }
            
            if (found) {
                max_xor = tentative;
            }
        }
        
        return max_xor;
    }
};