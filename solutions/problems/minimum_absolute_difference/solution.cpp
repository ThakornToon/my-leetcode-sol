class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // 1. เรียงลำดับ array
        sort(arr.begin(), arr.end());
        
        // 2. หาความแตกต่างน้อยที่สุด
        int minDiff = INT_MAX;
        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i-1];
            if (diff < minDiff) {
                minDiff = diff;
            }
        }
        
        // 3. เก็บคู่ทั้งหมดที่มีความแตกต่าง = minDiff
        vector<vector<int>> result;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i-1] == minDiff) {
                result.push_back({arr[i-1], arr[i]});
            }
        }
        
        return result;
    }
};