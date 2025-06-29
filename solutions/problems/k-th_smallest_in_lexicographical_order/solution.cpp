class Solution {
private:
    int countNodes(long long current, long long n) { // คำนวณจาก 1 -> 10 -> 100 -> 1000 ...
        long long count = 0;
        long long first = current;
        long long last = current;
        
        while (first <= n) { // 10 มีถึง 19, 100 มีถึง 199
            count += ((last < n) ? last : n) - first + 1;
            first *= 10;
            last = last * 10 + 9;
        }
        
        return count;
    }
public:
    int findKthNumber(int n, int k) {
        int current = 1;
        k--; // หาตัวที่ k ต้องข้ามไป k - 1
        
        while (k > 0) {
            int nodes = countNodes(current, n); // ดูว่าหากเจาลงไปด้วยเลขนำหน้าเป็น current จะมีกี่ตัว เช่น 1__, 10__, 11__ 
        
            if (k >= nodes) { // ดู 1___ แล้วค่า k ไม่อยู่ในโซนนี้จะไปเช็คหมวดถัดไป 2___, 3___ หรือ 10 -> 11
                // ไปยัง sibling ถัดไป
                current++;
                k -= nodes;
            } else { // รู้เลขนำหน้าว่าอยู่ในหมวดนี้ ค่อยๆลงลึก scope 1 -> 10 -> 100 -> ... -> 118 ที่ต้องการ
                // ลงลึกในระดับถัดไป
                current *= 10;
                k--;
            }
        }
        // เมื่อข้ามไป k - 1 ตัว current คือคำตอบ
        return current;
    }
};