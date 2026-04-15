class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> result(2);
        int minDiff = INT_MAX;
        
        // ลองทั้ง num+1 และ num+2
        for (int n : {num + 1, num + 2}) {
            int sqrtN = sqrt(n);
            
            // หาตัวประกอบที่ใกล้ sqrt มากที่สุด
            for (int a = sqrtN; a >= 1; a--) {
                if (n % a == 0) {
                    int b = n / a;
                    int diff = b - a;
                    
                    if (diff < minDiff) {
                        minDiff = diff;
                        result[0] = a;
                        result[1] = b;
                    }
                    break;  // เจอแล้วหยุด
                }
            }
        }
        
        return result;
    }
};