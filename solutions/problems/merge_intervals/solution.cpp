class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        //sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
        sort(intervals.begin(), intervals.end());
        int k = 0;
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[k][1] >= intervals[i][0]) { 
                intervals[k][1] = max(intervals[k][1], intervals[i][1]);
            } else {
                k++;
                intervals[k] = intervals[i];
            }
        }
        intervals.resize(k + 1);
        return intervals;        
    }
};