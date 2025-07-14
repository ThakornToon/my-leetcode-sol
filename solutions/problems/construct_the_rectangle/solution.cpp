class Solution {
public:
    vector<int> constructRectangle(int area) {
        int width = static_cast<int>(sqrt(area));
        while (area % width != 0) {
            width--;
        }
        return {area / width, width};
    }
};