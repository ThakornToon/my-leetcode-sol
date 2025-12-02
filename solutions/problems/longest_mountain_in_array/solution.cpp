class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;
        
        int maxLen = 0;
        int up = 0, down = 0;
        
        for (int i = 1; i < n; i++) {
            // Case 1: กำลังกลับไปเพิ่มขึ้นใหม่(reset)
            if ((down > 0 && arr[i] > arr[i-1]) || arr[i] == arr[i-1]) {
                up = down = 0;
            }
            
            // Case 2: อัพเดท up/down
            if (arr[i] > arr[i-1]) {
                up++;
            } else if (arr[i] < arr[i-1]) {
                down++;
            }
            
            // Case 3: ถ้ามีทั้ง up และ down
            if (up > 0 && down > 0) {
                maxLen = max(maxLen, up + down + 1);
            }
        }
        
        return maxLen;
    }
};