class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.length();
    
        for (int i = 0; i < n && k > 0; i++) {
            // หาตำแหน่งของตัวเลขที่น้อยที่สุดในช่วง i ถึง i+k
            int minPos = i;
            for (int j = i + 1; j <= min(i + k, n - 1); j++) {
                if (num[j] < num[minPos]) {
                    minPos = j;
                }
            }
            
            // ถ้าตัวเลขที่น้อยที่สุดไม่อยู่ที่ตำแหน่ง i
            if (minPos != i) {
                // นำตัวเลขที่ minPos มาไว้ที่ i
                char ch = num[minPos];
                // เลื่อนตัวเลขจาก i ถึง minPos-1 ไปทางขวา
                for (int j = minPos; j > i; j--) {
                    num[j] = num[j - 1];
                }
                num[i] = ch;
                
                // ลด k ด้วยระยะทาง
                k -= (minPos - i);
            }
        }
        
        return num;
    }
};