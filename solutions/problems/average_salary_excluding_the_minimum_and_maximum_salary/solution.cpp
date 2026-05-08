class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        long long sum = accumulate(salary.begin() + 1, salary.end() - 1, 0LL);
        return (double)sum / (salary.size() - 2);
    }
};