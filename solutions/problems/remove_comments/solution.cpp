class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        string current_line = "";
        bool in_block = false;

        for (string& line : source) {
            int i = 0;  // index ของ line ปัจจุบัน
            if (!in_block) {
                current_line = "";
            }

            while (i < line.length()) {
                // เจอเปิด block comment
                if (!in_block && i + 1 < line.length() && line[i] == '/' && line[i + 1] == '*') {
                    in_block = true;
                    i += 2;
                }
                // เจอ line comment
                 else if (!in_block && i + 1 < line.length() && line[i] == '/' && line[i + 1] == '/') {
                    break; // Line comment ข้ามส่วนที่เหลือของบรรทัดนี้
                } 
                // เจอปิด block comment
                else if (in_block && i + 1 < line.length() && line[i] == '*' && line[i + 1] == '/') {
                    in_block = false;
                    i += 2;
                } 
                // ข้อความทั่วไป
                else {
                    if (!in_block) {
                        current_line += line[i];
                    }
                    i++;
                }
            }

            // Add ข้อความที่ไม่อยู่ใน comment
            if (!in_block && !current_line.empty()) {
                res.push_back(current_line);
            }
        }
        return res;
    }
};