/*
ในแฟคทอเรียลจะมีตัวประกอบของ 2 มากกว่า 5 เสมอ
ดังนั้น จำนวนศูนย์ท้าย = จำนวนครั้งที่ 5 หาร x! ลงตัว
f(x) = x//5 + x//25 + x//125 + x//625 + ...

คำตอบจะเป็นได้แค่ 0 หรือ 5 เท่านั้น เพราะ:
ถ้ามีค่า K ในช่วง จะมีเลข 5 ตัวที่ให้ค่าเดียวกัน
ถ้าไม่มีค่า K ในช่วง คำตอบคือ 0
*/
class Solution {
public:
    int preimageSizeFZF(int k) {
        long long left = 0;
        long long right = 5L * (k + 1);
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            int zeros = 0;
            long long num = mid;
            while (num > 0) {
                num /= 5;
                zeros += num;
            }
            
            if (zeros == k) {
                return 5;
            } else if (zeros < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return 0;
    }
};