class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int i = n - 1;

        while (i >= 0) {
            int val = arr[i];
            int count = 0;
            
            while (i >= 0 && arr[i] == val) {
                count++;
                i--;
            }
            
            if (count == val) {
                return val;
            }
        }
        
        return -1;
    }
};