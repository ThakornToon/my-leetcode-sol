/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char* s, int* returnSize) {
    int len = strlen(s);
    
    // บันทึกตำแหน่งสุดท้ายของแต่ละตัวอักษร
    int last[26] = {0};
    for (int i = 0; i < len; i++) {
        last[s[i] - 'a'] = i;
    }
    
    // จอง memory สำหรับผลลัพธ์ (สูงสุด 26 parts)
    int* result = (int*)malloc(26 * sizeof(int));
    int count = 0;  // นับจำนวน parts
    
    int start = 0;  // จุดเริ่มต้นของส่วนปัจจุบัน
    int end = 0;    // จุดสิ้นสุดของส่วนปัจจุบัน
    
    for (int i = 0; i < len; i++) {
        // ขยายขอบเขตให้ครอบคลุมตำแหน่งสุดท้ายของตัวอักษรนี้
        if (last[s[i] - 'a'] > end) {
            end = last[s[i] - 'a'];
        }
        
        // ถ้าถึงจุดสิ้นสุดของส่วนปัจจุบัน
        if (i == end) {
            result[count++] = end - start + 1;  // บันทึกความยาว
            start = i + 1;  // เริ่มส่วนใหม่
        }
    }
    
    *returnSize = count;
    return result;
}