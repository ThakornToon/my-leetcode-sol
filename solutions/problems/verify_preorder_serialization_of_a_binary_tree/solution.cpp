class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        int n = preorder.length();

        for (int i = 0; i < n; ++i) {
            if (preorder[i] == ',') continue;

            // แต่ละโหนดใช้ 1 slot
            slots--;
            if (slots < 0) return false;

            // หากเป็นโหนดที่มีค่า (ไม่ใช่ '#') จะสร้าง slot ให้อีก 2 ช่อง
            if (preorder[i] != '#') {
                slots += 2;
                // ข้ามตัวเลขหลักที่เหลือของโหนดนี้ไปจนถึงเครื่องหมาย ','
                while (i + 1 < n && preorder[i + 1] != ',') {
                    i++;
                }
            }
        }

        return slots == 0;
    }
};