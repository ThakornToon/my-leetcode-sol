/*
encoded[1] = perm[1] XOR perm[2]
encoded[3] = perm[3] XOR perm[4]
...
encoded[n-2] = perm[n-2] XOR perm[n-1]

oddXor = perm[1] XOR perm[2] XOR perm[3] XOR perm[4] XOR ... XOR perm[n-2] XOR perm[n-1]
       = perm[1] XOR perm[2] XOR ... XOR perm[n-1]

totalXor = perm[0] XOR perm[1] XOR perm[2] XOR ... XOR perm[n-1]

totalXor XOR oddXor = perm[0] (เพราะทุกตัวยกเว้น perm[0] หายไป)
*/

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        vector<int> perm(n);
        
        // 1. คำนวณ XOR ของ 1 ถึง n
        int totalXor = 0;
        for (int i = 1; i <= n; i++) {
            totalXor ^= i;
        }
        
        // 2. คำนวณ XOR ของตำแหน่งคี่ใน encoded
        int oddXor = 0;
        for (int i = 1; i < encoded.size(); i += 2) {
            oddXor ^= encoded[i];
        }
        
        // 3. หา perm[0]
        perm[0] = totalXor ^ oddXor;
        
        // 4. ถอดรหัสที่เหลือ
        for (int i = 0; i < encoded.size(); i++) {
            perm[i + 1] = perm[i] ^ encoded[i];
        }
        
        return perm;
    }
};