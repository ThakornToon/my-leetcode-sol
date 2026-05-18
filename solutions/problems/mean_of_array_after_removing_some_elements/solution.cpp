class Solution {
public:
    double trimMean(vector<int>& arr) {
        // เรียงลำดับ array
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int removeCount = n / 20;  // 5% ของ n
        
        // รวมค่าที่อยู่ในช่วง [removeCount, n - removeCount - 1]
        double sum = accumulate(arr.begin() + removeCount, 
                                arr.begin() + n - removeCount, 
                                0.0);
        
        int remainingCount = n - 2 * removeCount;
        return sum / remainingCount;
    }
};