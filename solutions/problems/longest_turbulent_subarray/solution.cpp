class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        // inc: ความยาว turbulent ที่ลงท้ายด้วยขึ้น (arr[i] > arr[i-1])
        // dec: ความยาว turbulent ที่ลงท้ายด้วยลง (arr[i] < arr[i-1])
        int inc = 1, dec = 1;
        int maxLen = 1;
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) {
                // หากขึ้นต่อจากลง
                inc = dec + 1;
                dec = 1;  // เริ่มใหม่สำหรับ pattern ลง
            } else if (arr[i] < arr[i - 1]) {
                // หากลงต่อจากขึ้น
                dec = inc + 1;
                inc = 1;  // เริ่มใหม่สำหรับ pattern ขึ้น
            } else {
                // ค่าเท่ากัน
                inc = 1;
                dec = 1;
            }
            
            // หาค่าสูงสุดระหว่าง inc และ dec
            int currMax = inc > dec ? inc : dec;
            maxLen = currMax > maxLen ? currMax : maxLen;
        }
        
        return maxLen;
    }
};