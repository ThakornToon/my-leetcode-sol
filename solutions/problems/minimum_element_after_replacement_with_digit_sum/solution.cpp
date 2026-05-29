class Solution {
private:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int minVal = INT_MAX;
        
        for (int num : nums) {
            minVal = min(minVal, digitSum(num));
        }
        
        return minVal;
    }
};