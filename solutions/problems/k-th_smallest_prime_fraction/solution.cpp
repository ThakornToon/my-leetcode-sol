class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double left = 0.0, right = 1.0;
        int n = arr.size();
        
        while (left < right) {
            double mid = (left + right) / 2.0;
            int count = 0;
            int i = 0;
            double max_fraction = 0.0;
            int numerator = 0, denominator = 0;
            
            for (int j = 1; j < n; j++) {
                while (i < j && (double)arr[i] / arr[j] <= mid) {
                    double fraction = (double)arr[i] / arr[j];
                    if (fraction > max_fraction) {
                        max_fraction = fraction;
                        numerator = arr[i];
                        denominator = arr[j];
                    }
                    i++;
                }
                count += i;
            }
            
            if (count == k) {
                return {numerator, denominator};
            } else if (count < k) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        return {};
    }
};