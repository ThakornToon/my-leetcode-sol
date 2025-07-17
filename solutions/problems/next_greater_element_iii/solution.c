/*
หา pivot: หาตำแหน่งที่ตัวเลขเริ่มลดลงจากขวาไปซ้าย
หา successor: หาตัวเลขที่ใหญ่กว่าตัว pivot ที่อยู่ทางขวาสุด
สลับตำแหน่ง: สลับตัว pivot กับ successor
กลับลำดับส่วนที่เหลือ: กลับลำดับตัวเลขทางขวาของ pivot เพื่อให้ได้ค่าที่น้อยที่สุด
*/

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char* s, int start, int end) {
    while (start < end) {
        swap(&s[start], &s[end]);
        start++;
        end--;
    }
}

int nextGreaterElement(int n) {
    char s[20];
    sprintf(s, "%d", n);
    int len = strlen(s);
    
    // Find the pivot
    int pivot = len - 2;
    while (pivot >= 0 && s[pivot] >= s[pivot+1]) {
        pivot--;
    }
    
    if (pivot == -1) return -1;
    
    // Find the successor
    int successor = len - 1;
    while (s[successor] <= s[pivot]) {
        successor--;
    }
    
    // Swap
    swap(&s[pivot], &s[successor]);
    
    // Reverse the suffix
    reverse(s, pivot + 1, len - 1);
    
    // Convert back and check overflow
    long long result = atol(s);
    return (result > INT_MAX) ? -1 : result;
}