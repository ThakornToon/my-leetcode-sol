class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        if (n <= 2) {
            return n;
        }

        for (int i = 0; i < n; i++) {
            map<double, int> slopes;
            int count = 1;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int dy = y2 - y1;
                int dx = x2 - x1;
                double slope;
                if(dy == 0 && dx == 0){
                    count++; 
                    continue;
                } 

                if (dx != 0) {
                    slope = dy*1.0/dx;
                } else {
                    slope = INT_MAX;
                }
                slopes[slope]++;
            }

            for (auto& kv : slopes) {
                ans = max(ans, kv.second + count);
            }

        }

        return ans;
    }
};