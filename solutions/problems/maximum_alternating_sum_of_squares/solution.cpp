class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> vals;
        for (int x : nums) {
            vals.push_back(abs((long long)x));
        }
        sort(vals.begin(), vals.end());
        
        long long score = 0;
        int l = 0, r = n - 1;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                score += vals[r] * vals[r]; // ตำแหน่งคู่: บวกด้วยค่าที่มากที่สุด
                r--;
            } else {
                score -= vals[l] * vals[l]; // ตำแหน่งคี่: ลบด้วยค่าที่น้อยที่สุด
                l++;
            }
        }
        return score;
    }
};