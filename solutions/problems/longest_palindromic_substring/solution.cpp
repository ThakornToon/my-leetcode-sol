class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        // เก็บจุดศูนย์กลางและขนาดรัศมี palindrome ที่ยาวที่สุด
        int max_len = 0;
        int center = 0;
        vector<int> radii(2 * len + 1, 0); // เก็บขนาดของรัศมีสูงสุดเมื่อใช้จุดต่างๆเป็นจุดศูนย์กลางในการพิจารณา
/*
        แปลง
        abba -> #a#b#b#a# เพื่อเช็คกรณี palindrome ขนาดคู่และคี่
        ababa -> #a#b#a#b#a#
*/
        int C = 0, R = 0; // เก็บขอบเขตของ palindrome เพื่อเอามาช่วยลดการคิดซ้ำ

        for (int i = 0; i < 2 * len + 1; i++) { // พิจารณาทีละจุด
/*
            สมมติ #a#b#a#b#a# เมื่อพิจารณาที่ index 7 ขอบเขตที่ไกลสุดคือ C = 5, R = 5
            เมื่อเราพิจารณา b ที่ index 7 ให้เราอิงจากค่ารัศมีของ index 3 มาคิดต่อได้เลย
            แต่ต้องระวังหากรัศมีนั้นทำให้เกิดขอบเขตของ C = 5, R = 5 เราจะใช้ลักษณะการสมมาตรในแค่ในขอบเขตนี้
*/
            if (i < C + R) {
                int mirror = 2 * C - i; // หาตำแหน่งตัวสมมาตรที่อยู่ทางซ้าย
                radii[i] = min(radii[mirror], C + R - i); // ถ้าเกินขอบเขตเราจะใช้ C + R - i มาเริ่มต้นคิดรัศมี
            }

            // ขยายขนาดจากศูนย์กลาง i ถ้าเป็น # หมายความว่าเราพิจารณา palindrome คู่
            while (true) {
                int left = i - radii[i] - 1; // ตัวพิจารณาทางซ้าย
                int right = i + radii[i] + 1; // ตัวพิจารณาทางขวา
                if (left < 0 || right >= 2 * len + 1) { // ออกนอกขอบเขต
                    break;
                }

                if (left % 2 == 0 || s[left / 2] == s[right / 2]) { // ถ้า left, right เป็น index คู่แปลว่ากำลังพิจารณา # กับ #
                    radii[i]++;
                } else {
                    break;
                }
            }
            // แก้ไขกรณีพบค่าที่มากกว่า
            if (radii[i] > max_len) {
                max_len = radii[i];
                center = i;
            }
            // แก้ไขกรณีพบขอบเขตไกลขึ้น
            if (i + radii[i] > C + R) {
                C = i;
                R = radii[i];
            }
        }

        int start = (center - max_len) / 2;
        return s.substr(start, max_len);
    }
};