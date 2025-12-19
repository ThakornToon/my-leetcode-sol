/*
จำนวน 111...1 (n ตัว) สามารถเขียนเป็น (10^n - 1) / 9
ดังนั้นเราต้องหา n ที่น้อยที่สุดที่ทำให้ (10^n - 1) % (9K) == 0
หรือเท่ากับหา n ที่ 10^n ≡ 1 (mod 9K)
ถ้า K เป็นพหุคูณของ 2 หรือ 5 จะหาไม่ได้ (เพราะ 10^n mod K จะไม่เป็น 1)

N ≡ 0 (mod K)
(10^n - 1) / 9 ≡ 0 (mod K)
10^n ≡ 1 (mod 9K)
เพื่อเลี่ยงปัญหากับเลข 9 
R(1) = 1 mod K
R(2) = 11 mod K = (R(1)×10 + 1) mod K
R(3) = 111 mod K = (R(2)×10 + 1) mod K
...
R(n) = (R(n-1)×10 + 1) mod 
Remainder มีค่าที่เป็นไปได้: 0, 1, 2, ..., K-1 (ทั้งหมด K ค่า)
*/
int smallestRepunitDivByK(int k) {
    // ถ้า K เป็นพหุคูณของ 2 หรือ 5 จะไม่มีคำตอบ
    if (k % 2 == 0 || k % 5 == 0) {
        return -1;
    }
    
    int remainder = 0;
    
    // เราต้องทดสอบมากสุด K ครั้ง
    for (int length = 1; length <= k; length++) {
        remainder = (remainder * 10 + 1) % k;
        
        if (remainder == 0) {
            return length;
        }
    }
    
    return -1;
}