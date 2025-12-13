class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        
        // เดินจากซ้ายไปขวาเพื่อหาความชันขึ้น
        while (left + 1 < arr.size() && arr[left] < arr[left + 1]) {
            left++;
        }
        
        // เดินจากขวาไปซ้ายเพื่อหาความชันลง
        while (right > 0 && arr[right] < arr[right - 1]) {
            right--;
        }
        
        // ตรวจสอบว่าพบยอดเขาเดียวกันและยอดเขาไม่อยู่ที่ขอบ
        return left > 0 && right < arr.size() - 1 && left == right;
    }
};