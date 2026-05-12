class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int count = 0;
        
        for (int j = 1; j < n - 1; j++) {
            // หา i
            vector<int> validI;
            for (int i = 0; i < j; i++) {
                if (abs(arr[i] - arr[j]) <= a) {
                    validI.push_back(i);
                }
            }
            
            // หา k
            vector<int> validK;
            for (int k = j + 1; k < n; k++) {
                if (abs(arr[j] - arr[k]) <= b) {
                    validK.push_back(k);
                }
            }
            
            // ตรวจสอบคู่ (i, k)
            for (int iIdx : validI) {
                for (int kIdx : validK) {
                    if (abs(arr[iIdx] - arr[kIdx]) <= c) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};