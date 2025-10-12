class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort intervals by end ascending, then by start descending
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) {
                return a[0] > b[0]; // start descending
            }
            return a[1] < b[1]; // end ascending
        });
        
        int result = 0;
        int last = -1;
        int second_last = -1;
        
        for (const auto& interval : intervals) {
            int a = interval[0];
            int b = interval[1];
            
            if (a > last) {
                // Case 1: Need to add 2 new numbers
                result += 2;
                last = b;
                second_last = b - 1;
            } else if (a > second_last) {
                // Case 2: Need to add 1 new number
                result += 1;
                second_last = last;
                last = b;
            }
            // Case 3: Already covered by existing numbers
        }
        
        return result;
    }
};