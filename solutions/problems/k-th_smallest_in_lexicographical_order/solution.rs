impl Solution {
    fn countNodes(current: i32, n: i64) -> i32 { // คำนวณจาก 1 -> 10 -> 100 -> 1000 ...
        let mut count: i64 = 0;
        let mut first = current as i64;
        let mut last = current as i64;
        
        while (first <= n) { // 10 มีถึง 19, 100 มีถึง 199
            if (last < n) {
                count += last - first + 1;
            } else {
                count += n - first + 1;
            }
            first *= 10;
            last = last * 10 + 9;
        }
        
        return count as i32;
    }
    pub fn find_kth_number(n: i32, k: i32) -> i32 {
        let mut current: i32 = 1;
        let mut k = k;
        k -= 1; // หาตัวที่ k ต้องข้ามไป k - 1
        
        while (k > 0) {
            let nodes = Self::countNodes(current, n as i64); // ดูว่าหากเจาลงไปด้วยเลขนำหน้าเป็น current จะมีกี่ตัว เช่น 1__, 10__, 11__ 
        
            if (k >= nodes) { // ดู 1___ แล้วค่า k ไม่อยู่ในโซนนี้จะไปเช็คหมวดถัดไป 2___, 3___ หรือ 10 -> 11
                // ไปยัง sibling ถัดไป
                current += 1;
                k -= nodes;
            } else { // รู้เลขนำหน้าว่าอยู่ในหมวดนี้ ค่อยๆลงลึก scope 1 -> 10 -> 100 -> ... -> 118 ที่ต้องการ
                // ลงลึกในระดับถัดไป
                current *= 10;
                k -= 1;
            }
        }
        // เมื่อข้ามไป k - 1 ตัว current คือคำตอบ
        return current;
    }
}