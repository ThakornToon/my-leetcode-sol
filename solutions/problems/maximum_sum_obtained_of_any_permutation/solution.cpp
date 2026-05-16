class Solution {
private:
    const int MOD = 1000000007;
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        
        // สร้าง array สำหรับนับความถี่ของแต่ละ index
        vector<long long> freq(n + 1, 0);
        
        // ใช้เทคนิค difference array เพื่อเพิ่มความถี่ในช่วง [start, end]
        for (const auto& req : requests) {
            int start = req[0];
            int end = req[1];
            freq[start]++;
            if (end + 1 < n) {
                freq[end + 1]--;
            }
        }
        
        // ทำ prefix sum เพื่อหาความถี่ที่แท้จริงของแต่ละ index
        for (int i = 1; i < n; i++) {
            freq[i] += freq[i - 1];
        }
        
        // เอา element สุดท้ายออก (freq[n] ใช้แค่ช่วยคำนวณ)
        freq.resize(n);
        
        // เรียงลำดับ freq จากมากไปน้อย
        sort(freq.begin(), freq.end(), greater<long long>());
        
        // เรียงลำดับ nums จากมากไปน้อย
        sort(nums.begin(), nums.end(), greater<int>());
        
        // คำนวณผลรวม: freq[i] * nums[i] สำหรับทุก i
        long long total = 0;
        for (int i = 0; i < n; i++) {
            total = (total + (freq[i] % MOD) * (nums[i] % MOD)) % MOD;
        }
        
        return (int)total;
    }
};