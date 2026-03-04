class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxRight = -1;
        
        // วนจากขวาไปซ้าย
        for (int i = n - 1; i >= 0; i--) {
            int current = arr[i];
            arr[i] = maxRight;
            maxRight = max(maxRight, current);
        }
        
        return arr;
    }
};