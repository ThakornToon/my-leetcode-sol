class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit_count(31, 0);
        
        // นับความถี่ของบิต 1 ในแต่ละตำแหน่ง
        for (int num : nums) {
            for (int i = 0; i < 31; ++i) {
                if ((num >> i) & 1) {
                    bit_count[i]++;
                }
            }
        }
        
        long long ans = 0;
        long long MOD = 1e9 + 7;
        
        // สร้างตัวเลขใหม่ k ตัวที่มีค่ามากที่สุดเท่าที่จะเป็นไปได้
        for (int j = 0; j < k; ++j) {
            long long cur = 0;
            for (int i = 0; i < 31; ++i) {
                if (bit_count[i] > 0) {
                    cur |= (1LL << i);
                    bit_count[i]--;  // ใช้บิต 1 ไปแล้ว 1 ตัว
                }
            }
            ans = (ans + (cur * cur) % MOD) % MOD;
        }
        
        return ans;
    }
};