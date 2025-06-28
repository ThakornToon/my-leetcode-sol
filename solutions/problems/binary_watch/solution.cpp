class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (bitset<10>((h << 6) | m).count() == turnedOn) {
/*
                h << 6: เลื่อนบิตของชั่วโมงไปทางซ้าย 6 ตำแหน่ง (ชั่วโมงใช้ 4 บิต (0-11) ย้ายไปอยู่ตำแหน่งบิตที่ 6-9)
                | m: ผนวกค่าของนาที (6 บิต) ที่ตำแหน่งบิต 0-5
                bitset<10>(...) สร้าง object bitset ขนาด 10 บิตจากค่าที่คำนวณได้
                .count() เป็นเมธอดของ bitset ที่นับจำนวนบิตที่มีค่าเป็น 1
*/
                    result.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }
        return result;

    }
};