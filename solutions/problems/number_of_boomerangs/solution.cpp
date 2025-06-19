class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int result = 0;
        for (auto &p : points) {
            unordered_map<int, int> distMap;
            for (auto &q : points) {
                int dx = p[0] - q[0];
                int dy = p[1] - q[1];
                int dist = dx*dx + dy*dy;
                distMap[dist]++;
            }
            for (auto &[dist, count] : distMap) {
                result += count * (count - 1);
            }
        }
        return result;
    }
};