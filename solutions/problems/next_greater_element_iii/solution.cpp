/*
หา pivot: หาตำแหน่งที่ตัวเลขเริ่มลดลงจากขวาไปซ้าย
หา successor: หาตัวเลขที่ใหญ่กว่าตัว pivot ที่อยู่ทางขวาสุด
สลับตำแหน่ง: สลับตัว pivot กับ successor
กลับลำดับส่วนที่เหลือ: กลับลำดับตัวเลขทางขวาของ pivot เพื่อให้ได้ค่าที่น้อยที่สุด
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int pivot = s.length() - 2;
        
        // Find the pivot
        while (pivot >= 0 && s[pivot] >= s[pivot+1]) {
            pivot--;
        }
        
        if (pivot == -1) return -1;
        
        // Find the successor
        int successor = s.length() - 1;
        while (s[successor] <= s[pivot]) {
            successor--;
        }
        
        // Swap
        swap(s[pivot], s[successor]);
        
        // Reverse the suffix
        reverse(s.begin() + pivot + 1, s.end());
        
        // Check for overflow
        long long result = stol(s);
        return (result > INT_MAX) ? -1 : result;
       
    }
};