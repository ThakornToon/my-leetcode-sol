
/*
0110
0011
ได้
0101
0100
ทำแบบเดิมไปเรื่อยๆจะได้
1001
ถ้าตำแหน่งนั้นเป็น 1 + 1 เราจะให้เป็น 0 แล้วทดเลข 1 ไปเพิ่มตำแหน่งถัดไป
*/
impl Solution {
    pub fn get_sum(a: i32, b: i32) -> i32 {
        let mut a = a;
        let mut b = b;
        while b != 0 {
            let carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        a
    }
}