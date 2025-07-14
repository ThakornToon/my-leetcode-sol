class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int count = 0;
        int start = 0;
        for (int time : timeSeries) {
            start = max(start, time);
            count += (time + duration - start) > 0 ? (time + duration - start) : 0;
            start = time + duration;
        }
        return count;
    }
};