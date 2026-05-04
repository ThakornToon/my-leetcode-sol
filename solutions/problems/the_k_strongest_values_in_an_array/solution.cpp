class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int median = arr[(n - 1) / 2];
        
        vector<int> result;
        int left = 0, right = n - 1;
        
        while (result.size() < k) {
            int leftDiff = abs(arr[left] - median);
            int rightDiff = abs(arr[right] - median);
            
            if (leftDiff > rightDiff) {
                result.push_back(arr[left++]);
            } else if (leftDiff < rightDiff) {
                result.push_back(arr[right--]);
            } else {
                // ถ้าเท่ากัน ให้เอาค่ามากกว่า
                if (arr[left] > arr[right]) {
                    result.push_back(arr[left++]);
                } else {
                    result.push_back(arr[right--]);
                }
            }
        }
        
        return result;
    }
};