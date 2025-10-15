/*
ในแฟคทอเรียลจะมีตัวประกอบของ 2 มากกว่า 5 เสมอ
ดังนั้น จำนวนศูนย์ท้าย = จำนวนครั้งที่ 5 หาร x! ลงตัว
f(x) = x//5 + x//25 + x//125 + x//625 + ...

คำตอบจะเป็นได้แค่ 0 หรือ 5 เท่านั้น เพราะ:
ถ้ามีค่า K ในช่วง จะมีเลข 5 ตัวที่ให้ค่าเดียวกัน
ถ้าไม่มีค่า K ในช่วง คำตอบคือ 0
*/
impl Solution {
    pub fn preimage_size_fzf(k: i32) -> i32 {
        let k = k as i64;
        let mut left: i64 = 0;
        let mut right: i64 = 5 * (k + 1);
        
        while left <= right {
            let mid = left + (right - left) / 2;
            let zeros = Self::trailing_zeroes(mid);
            
            match zeros.cmp(&k) {
                std::cmp::Ordering::Equal => return 5,
                std::cmp::Ordering::Less => left = mid + 1,
                std::cmp::Ordering::Greater => right = mid - 1,
            }
        }
        0
    }

    fn trailing_zeroes(mut n: i64) -> i64 {
        let mut count = 0;
        while n > 0 {
            n /= 5;
            count += n;
        }
        count
    }
}