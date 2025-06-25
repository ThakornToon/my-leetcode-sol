class Solution {
public:
    vector<int> grayCode(int n) {
        std::vector<int> result;
        for (int i = 0; i < (1 << n); ++i) {
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};
/*
การเปลี่ยนบิตเดียว: เมื่อเลขเพิ่มขึ้น 1 การเปลี่ยนแปลงจะเกิดที่บิตขวาสุด (least significant bit)

XOR จะเก็บการเปลี่ยนแปลงนี้: การ XOR กับตัวมันที่ถูก shift ไปขวา 1 บิต ทำให้ได้การเปลี่ยนแปลงทีละบิต
*/