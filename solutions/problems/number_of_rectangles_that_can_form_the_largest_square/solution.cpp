class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        // สร้าง vector ของด้านที่สั้นที่สุด
        vector<int> sides;
        for (const auto& rect : rectangles) {
            sides.push_back(min(rect[0], rect[1]));
        }
        
        // หาค่าสูงสุด
        int maxLen = *max_element(sides.begin(), sides.end());
        
        // นับจำนวนที่มีค่าเท่ากับ maxLen
        return count(sides.begin(), sides.end(), maxLen);
    }
};