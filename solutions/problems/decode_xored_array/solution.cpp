class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> arr(n + 1);
        
        // ค่าแรกคือ first
        arr[0] = first;
        
        // คำนวณค่าถัดไปโดยใช้ XOR
        for (int i = 0; i < n; i++) {
            arr[i + 1] = arr[i] ^ encoded[i];
        }
        
        return arr;
    }
};