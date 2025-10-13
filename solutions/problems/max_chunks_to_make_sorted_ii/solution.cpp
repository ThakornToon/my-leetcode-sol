class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        
        // สร้าง suffix min array
        vector<int> suffix_min(n);
        suffix_min[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffix_min[i] = min(arr[i], suffix_min[i+1]);
        }
        
        int chunks = 1;  // chunks อย่างน้อย 1
        int prefix_max = arr[0];
        
        for (int i = 0; i < n-1; i++) {
            prefix_max = max(prefix_max, arr[i]);
            
            // ถ้าค่าสูงสุดของ chunk ซ้าย <= ค่าต่ำสุดของ chunk ขวา
            if (prefix_max <= suffix_min[i+1]) {
                chunks++;
            }
        }
        
        return chunks;
    }
};