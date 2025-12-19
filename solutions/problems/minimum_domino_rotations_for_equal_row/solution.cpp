class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
int n = tops.size();
        int result = INT_MAX;
        
        // ลองทั้งสองตัวเลือกที่เป็นไปได้
        result = min(result, check(tops[0], tops, bottoms));
        result = min(result, check(bottoms[0], tops, bottoms));
        
        return result == INT_MAX ? -1 : result;
    }
    
private:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int rotations_top = 0;
        int rotations_bottom = 0;
        
        for (int i = 0; i < n; i++) {
            // ถ้า domino ตัวนี้ไม่มี target เลย
            if (tops[i] != target && bottoms[i] != target) {
                return INT_MAX;
            }
            
            // นับจำนวนการหมุนที่ต้องการ
            if (tops[i] != target) {
                rotations_top++;
            }
            if (bottoms[i] != target) {
                rotations_bottom++;
            }
        }
        
        return min(rotations_top, rotations_bottom);
    }
};