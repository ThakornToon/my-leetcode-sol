class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int size = 1 << n;  // 2^n
        vector<int> result(size);
        
        for (int i = 0; i < size; i++) {
            // สร้าง gray code
            int gray = i ^ (i >> 1); // XOR ระหว่าง i กับ i ที่ shift ขวา 1 บิต
            // ทำให้เริ่มที่ start
            result[i] = gray ^ start;
        }
        
        /*
        H[i] ^ H[i+1] = (G[i] ^ start) ^ (G[i+1] ^ start)
            = G[i] ^ start ^ G[i+1] ^ start
            = G[i] ^ G[i+1] ^ (start ^ start)  // start ^ start = 0
            = G[i] ^ G[i+1]
        */
        
        return result;

    }
};