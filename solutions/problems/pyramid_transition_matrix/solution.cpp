class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // สร้างตารางกฎ: rules[left][right] บอกว่า top อะไรบ้างที่วางได้
        bool rules[7][7][7] = {false};
        
        // เก็บกฎทั้งหมดลงในตาราง
        for (string rule : allowed) {
            int left = rule[0] - 'A';   // ตัวซ้าย
            int right = rule[1] - 'A';  // ตัวขวา
            int top = rule[2] - 'A';    // ตัวบน
            rules[left][right][top] = true;
        }
        
        // ฟังก์ชันตรวจสอบว่าแถวนี้สร้างพีระมิดสำเร็จไหม
        return checkLevel(bottom, rules);
    }
    
private:
    bool checkLevel(string currentLevel, bool rules[7][7][7]) {
        // ถ้าเหลือแค่ตัวเดียว แปลว่าถึงยอดพีระมิดแล้ว
        if (currentLevel.length() == 1) {
            return true;
        }
        
        // พยายามสร้างแถวถัดไป
        string nextLevel = "";
        return buildNextLevel(0, currentLevel, nextLevel, rules);
    }
    
    bool buildNextLevel(int position, string& currentLevel, string nextLevel, bool rules[7][7][7]) {
        // ถ้าสร้างแถวถัดไปเสร็จแล้ว
        if (position == currentLevel.length() - 1) {
            // ตรวจสอบแถวถัดไป
            return checkLevel(nextLevel, rules);
        }
        
        // ดึงตัวซ้ายและตัวขวาจากแถวปัจจุบัน
        char leftChar = currentLevel[position];
        char rightChar = currentLevel[position + 1];
        
        // ลองทุกตัวอักษรที่สามารถวางบนซ้าย-ขวา นี้ได้
        for (char topChar = 'A'; topChar <= 'G'; topChar++) {
            // ตรวจสอบว่ากฎนี้ใช้ได้ไหม
            if (rules[leftChar-'A'][rightChar-'A'][topChar-'A']) {
                // สร้างแถวถัดไปโดยเพิ่มตัวบน
                string newNextLevel = nextLevel + topChar;
                
                // ลองสร้างตำแหน่งต่อไป
                if (buildNextLevel(position + 1, currentLevel, newNextLevel, rules)) {
                    return true;
                }
            }
        }
        
        // ทุกตัวอักษรลองแล้วไม่ได้ผล
        return false;
    }
};