class Solution {
private:
    int reverseNum(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        return rev;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mirrorMap;
        int minDist = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            int mirror = reverseNum(nums[i]);
            
            // ตรวจสอบว่า nums[i] เป็น mirror ของตัวก่อนหน้าหรือไม่
            if (mirrorMap.count(nums[i])) {
                minDist = min(minDist, i - mirrorMap[nums[i]]);
            }
            
            mirrorMap[mirror] = i;
        }
        
        return minDist == INT_MAX ? -1 : minDist;
    }
};