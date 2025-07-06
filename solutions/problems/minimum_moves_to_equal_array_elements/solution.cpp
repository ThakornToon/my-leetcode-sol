/*
การเพิ่ม n-1 ตัว เทียบเท่ากับการลด 1 ตัว:
แทนที่จะเพิ่ม n-1 ตัวทีละ 1 เราสามารถมองว่าเป็นการลด 1 ตัวทีละ 1
ตัวอย่าง: ในอาร์เรย์ [1,2,3]:
เพิ่ม [1,2] → [2,3,3] (เทียบเท่ากับลด 3 ลง 1 ได้ [1,2,2])
เพิ่ม [2,3] → [3,4,3] (เทียบเท่ากับลด 4 ลง 1 ได้ [3,3,3])
*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        // หาค่าต่ำสุด
        int min_num = *std::min_element(nums.begin(), nums.end());
        
        // คำนวณผลรวมของผลต่าง
        return std::accumulate(nums.begin(), nums.end(), 0, 
            [min_num](int sum, int num) { return sum + (num - min_num); });
            // [min_num]: จับตัวแปร min_num จากภายนอกมาใช้ใน lambda
            // (int sum, int num): พารามิเตอร์ของฟังก์ชัน
            // sum: ผลรวมสะสม
            // num: ค่าปัจจุบันในอาร์เรย์ที่กำลังประมวลผล
            // return sum + (num - min_num): เพิ่มผลต่างระหว่างค่าปัจจุบันกับค่าต่ำสุดลงในผลรวมสะสม
    }
};