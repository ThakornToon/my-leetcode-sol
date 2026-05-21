class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> freq;  // {val : freq}
        long long result = 0;
        
        for (int x : deliciousness) {
            // สำหรับทุก power of two ที่มากกว่า x
            for (int power = 1; power <= (1 << 21); power <<= 1) {
                int complement = power - x;
                if (complement < 0) continue;

                // หาคู่ในตำแหน่งก่อนหน้า (ใน hash map)
                if (freq.count(complement)) {
                    result = (result + freq[complement]) % MOD;
                }
            }

            // เก็บใน hash map
            freq[x]++;
        }
        
        return result;
    }
};