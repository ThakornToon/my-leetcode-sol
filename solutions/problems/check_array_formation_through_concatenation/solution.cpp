class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        // "the integers in pieces are distinct" (ตัวเลขทุกตัวใน pieces ทุกอันรวมกันไม่ซ้ำกัน)
        // สร้าง mapping จากค่าแรกไปยัง piece
        unordered_map<int, vector<int>> map;
        for (auto& piece : pieces) {
            map[piece[0]] = piece;
        }
        
        int i = 0;
        while (i < arr.size()) {
            // ถ้าไม่มี piece ที่ขึ้นต้นด้วย arr[i]
            if (map.find(arr[i]) == map.end()) {
                return false;
            }
            
            // ดึง piece ที่ match
            vector<int>& piece = map[arr[i]];
            
            // เปรียบเทียบ piece กับ arr
            for (int j = 0; j < piece.size(); j++) {
                if (i + j >= arr.size() || piece[j] != arr[i + j]) {
                    return false;
                }
            }
            
            // ข้ามไปยังตำแหน่งถัดไป
            i += piece.size();
        }
        
        return true;
    }
};