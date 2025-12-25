int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    // ใช้ array 2D 10x10 เพราะค่า domino มีแค่ 1-9
    int count[10][10] = {0};
    int result = 0;
    
    for (int i = 0; i < dominoesSize; i++) {
        int a = dominoes[i][0];
        int b = dominoes[i][1];
        
        // ทำให้ domino เป็น canonical form: (min, max)
        int x = a < b ? a : b;
        int y = a < b ? b : a;
        
        // ถ้ามี domino เดียวกันอยู่แล้ว n อันก่อนหน้า
        // domino ปัจจุบันจะสร้างคู่ได้ n คู่
        result += count[x][y];
        
        // เพิ่ม count สำหรับ domino ปัจจุบัน
        count[x][y]++;
    }
    
    return result;
}