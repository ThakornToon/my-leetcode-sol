/*
ใช้หลักการ "การทดสอบตามแกน" โดยให้หมูแต่ละตัวแทนหนึ่งมิติ (dimension) ในพื้นที่การทดสอบ
Ex. tests = 4, buckets = 25 -> pigs = 2 
จำนวนถังที่ตรวจสอบได้ = (tests + 1) ^ pigs
ถังที่ 1-25 จัดเรียงเป็นเมทริกซ์ 5x5: อย่าลืมว่าเราตรวจสอบได้ 4 ครั้ง หมูแต่ละตัวมีความเป็นไปได้ tests + 1 กรณีที่ตายในครั้งต่างๆและไม่ตายเลย
  1  2  3  4  5
  6  7  8  9 10
 11 12 13 14 15
 16 17 18 19 20
 21 22 23 24 25
*/

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int tests = minutesToTest / minutesToDie;
        int pigs = 0;
        int sum = 1;
        while (sum < buckets) {
            sum *= (tests + 1);
            pigs += 1;
        }
        return pigs;
    }
};