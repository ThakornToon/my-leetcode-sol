/*
|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
|x| = max(x, -x) จะมีทั้งหมด 8 กรณ๊
1. (+1, +1, +1): (A+B+i) - (A+B+j)
2. (+1, +1, -1): (A+B-i) - (A+B-j)
3. (+1, -1, +1): (A-B+i) - (A-B+j)
4. (+1, -1, -1): (A-B-i) - (A-B-j)
--------------------------------------
5. (-1, +1, +1): (-A+B+i) - (-A+B+j)
6. (-1, +1, -1): (-A+B-i) - (-A+B-j)
7. (-1, -1, +1): (-A-B+i) - (-A-B+j)
8. (-1, -1, -1): (-A-B-i) - (-A-B-j)
สังเกตว่าถ้าแบ่งแบบนี้เครื่องหมายหน้า (A1, B1, i) จะเหมือนกับ (A2, B2, j)
และสามารถลดให้เหลือแค่ 4 กรณีได้จากการสลับ i, j ในการคิด

ค่าสูงสุดของ X[i] - X[j] เกิดเมื่อ X[i] สูงสุดและ X[j] ต่ำสุด
ค่าลบ (X[j] - X[i]) ไม่จำเป็น เพราะเราเลือก i, j ให้ได้ค่าบวกสูงสุดได้
สุดท้ายเราสนใจแค่ max(X) - min(X) ซึ่งคำนวณจากทุก index แล้วนำไปคิดในสี่กรณี
จะได้กรณีที่ดีที่สุดเมื่อกรณีนั้นเราใส่เครื่องหมายแทนค่าสมบูรณ์ถูกต้อง
*/

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        
        // กำหนดค่าเริ่มต้น
        int max1 = INT_MIN, min1 = INT_MAX;  // สำหรับ arr1[i] + arr2[i] + i
        int max2 = INT_MIN, min2 = INT_MAX;  // สำหรับ arr1[i] + arr2[i] - i
        int max3 = INT_MIN, min3 = INT_MAX;  // สำหรับ arr1[i] - arr2[i] + i
        int max4 = INT_MIN, min4 = INT_MAX;  // สำหรับ arr1[i] - arr2[i] - i
        
        for (int i = 0; i < n; i++) {
            int val1 = arr1[i] + arr2[i] + i;
            int val2 = arr1[i] + arr2[i] - i;
            int val3 = arr1[i] - arr2[i] + i;
            int val4 = arr1[i] - arr2[i] - i;
            
            max1 = max(max1, val1);
            min1 = min(min1, val1);
            
            max2 = max(max2, val2);
            min2 = min(min2, val2);
            
            max3 = max(max3, val3);
            min3 = min(min3, val3);
            
            max4 = max(max4, val4);
            min4 = min(min4, val4);
        }
        
        // คำนวณค่าสูงสุดจากทั้ง 4 กรณี
        int result = 0;
        result = max(result, max1 - min1);
        result = max(result, max2 - min2);
        result = max(result, max3 - min3);
        result = max(result, max4 - min4);
        
        return result;
    }
};