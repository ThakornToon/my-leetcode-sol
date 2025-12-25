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
ถ้าเราต้องการหาค่า max ของ |X| + |Y| + |Z| มันเท่ากับหา max ของผลต่างระหว่าง (±X ± Y ± Z) และ max((±a ± b ± c) for i,j) = max(max(±arr1[i] ± arr2[i] ± i) - min(±arr1[j] ± arr2[j] ± j))
สุดท้ายเราสนใจแค่ max(X) - min(X) ซึ่งคำนวณจากทุก index แล้วนำไปคิดในสี่กรณี
จะได้กรณีที่ดีที่สุดเมื่อกรณีนั้นเราใส่เครื่องหมายแทนค่าสมบูรณ์ถูกต้อง
*/

int maxAbsValExpr(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    int n = arr1Size;
    
    int max1 = INT_MIN, min1 = INT_MAX;
    int max2 = INT_MIN, min2 = INT_MAX;
    int max3 = INT_MIN, min3 = INT_MAX;
    int max4 = INT_MIN, min4 = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        int val1 = arr1[i] + arr2[i] + i;
        int val2 = arr1[i] + arr2[i] - i;
        int val3 = arr1[i] - arr2[i] + i;
        int val4 = arr1[i] - arr2[i] - i;
        
        if (val1 > max1) max1 = val1;
        if (val1 < min1) min1 = val1;
        
        if (val2 > max2) max2 = val2;
        if (val2 < min2) min2 = val2;
        
        if (val3 > max3) max3 = val3;
        if (val3 < min3) min3 = val3;
        
        if (val4 > max4) max4 = val4;
        if (val4 < min4) min4 = val4;
    }
    
    int result = 0;
    int diff1 = max1 - min1;
    int diff2 = max2 - min2;
    int diff3 = max3 - min3;
    int diff4 = max4 - min4;
    
    if (diff1 > result) result = diff1;
    if (diff2 > result) result = diff2;
    if (diff3 > result) result = diff3;
    if (diff4 > result) result = diff4;
    
    return result;
}