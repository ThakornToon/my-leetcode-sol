class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int radius = 0;
        
        for (int house : houses) {
            int closest = findClosestHeater(heaters, house);
            radius = max(radius, closest);
        }
        
        return radius;
    }
    
private:
    int findClosestHeater(const vector<int>& heaters, int house) {
        int left = 0;
        int right = heaters.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (heaters[mid] < house) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (left == 0) {
            return abs(heaters[0] - house);
        }
        if (left == heaters.size()) {
            return abs(house - heaters.back());
        }
        return min(abs(heaters[left] - house), abs(house - heaters[left - 1]));
    }
};