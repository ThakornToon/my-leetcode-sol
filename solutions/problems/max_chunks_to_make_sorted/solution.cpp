class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max_val = 0;
        int chunks = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            max_val = max(max_val, arr[i]);
            
            // ถ้าค่าสูงสุดเท่ากับ index ปัจจุบัน แสดงว่าแบ่ง chunk ได้
            if (max_val == i) {
                chunks++;
            }
        }
        
        return chunks;

    }
};