class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        while (columnNumber > 0) { //BYC -> เหมือนการแปลงเลขฐานสิบกับยี่สิบหก 3+(26*25)+(26*26*2)
            columnNumber--; //ลดค่าเพื่อให้ A=0, B=1, ..., Z=25
            s = char((columnNumber % 26) + 'A') + s;
            columnNumber /= 26;
        }
        return s;
    }
};