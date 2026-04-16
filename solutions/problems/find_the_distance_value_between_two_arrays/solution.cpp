class Solution {
private:
    // Binary search: หาตำแหน่งแรกที่ arr[mid] >= target
    int binarySearch(const vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        int result = arr.size();
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] >= target) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // sort arr2
        sort(arr2.begin(), arr2.end());
        
        int count = 0;
        
        for (int x : arr1) {
            int pos = binarySearch(arr2, x);
            
            bool isValid = true;
            
            // ตรวจสอบ element ทางขวา (>= x)
            if (pos < arr2.size()) {
                if (abs(arr2[pos] - x) <= d) {
                    isValid = false;
                }
            }
            
            // ตรวจสอบ element ทางซ้าย (< x)
            if (pos - 1 >= 0) {
                if (abs(arr2[pos - 1] - x) <= d) {
                    isValid = false;
                }
            }
            
            if (isValid) {
                count++;
            }
        }
        
        return count;
    }
};