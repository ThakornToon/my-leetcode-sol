class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stack;
        
        for (char digit : num) {
            while (k > 0 && !stack.empty() && stack.back() > digit) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }
        
        // ลบตัวเลขที่เหลือถ้า k > 0
        stack.resize(stack.size() - k);
        
        // สร้างผลลัพธ์และลบ 0 นำหน้า
        string result(stack.begin(), stack.end());
        result.erase(0, result.find_first_not_of('0')); // ค้นหาตำแหน่งแรกในสตริง result ที่ไม่ใช่ตัวอักษร '0' แล้วลบตัวอักษรในสตริงเริ่มจากตำแหน่งที่ 0 เป็นจำนวน pos ตัว
        return result.empty() ? "0" : result; 
    }
};