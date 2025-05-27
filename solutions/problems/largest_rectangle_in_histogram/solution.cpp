class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        int area = 0;
        vector<int>stack = {-1};
        for (int i = 0; i < size; i++) {
            while (stack.back() != -1 && heights[i] <= heights[stack.back()]) {
                int height = heights[stack.back()];
                stack.pop_back();
                int width = i - 1 - stack.back();
                area = max(area, height * width);
            }
            stack.push_back(i);
        }
        while (stack.back() != -1) {
            int height = heights[stack.back()];
            stack.pop_back();
            int width = heights.size() - stack.back() - 1;
            area = max(area, height * width);
        }
        return area;
    }
};