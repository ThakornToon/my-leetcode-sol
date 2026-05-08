class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> result(n, 1);
        unordered_map<int, int> lastRain; // lake -> last rain day index
        set<int> sunnyDays;
        
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                sunnyDays.insert(i);
            } else {
                int lake = rains[i];
                if (lastRain.count(lake)) {
                    // find a sunny day after last rain (binary search)
                    auto it = sunnyDays.upper_bound(lastRain[lake]);
                    if (it == sunnyDays.end()) {
                        return {};
                    }
                    int sunnyDay = *it;
                    result[sunnyDay] = lake;
                    sunnyDays.erase(it);
                }
                result[i] = -1;
                lastRain[lake] = i;
            }
        }
        
        return result;
    }
};