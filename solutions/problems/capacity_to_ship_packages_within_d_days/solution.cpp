class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minCapacity = 0;
        int maxCapacity = 0;
        for (auto& w : weights) {
            if (w > minCapacity) {
                minCapacity = w;
            }
            maxCapacity += w;
        }
        while (minCapacity < maxCapacity) {
            int mid = minCapacity + (maxCapacity - minCapacity) / 2;
            int sum = 0;
            int Cday = 1;
            for (auto& w : weights) {
                if (sum + w > mid) {
                    sum = 0;
                    Cday++;
                }
                sum += w;
            }
            if (Cday <= days) {
                maxCapacity = mid;
            } else {
                minCapacity = mid + 1;
            }
        }
        return maxCapacity;
    }
};