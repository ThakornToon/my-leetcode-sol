class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count, end;
        
        // Count frequency
        for (int num : nums) {
            count[num]++;
        }
        
        for (int num : nums) {
            if (count[num] == 0) continue;
            
            count[num]--;
            
            // Prefer to append to existing subsequence
            if (end[num - 1] > 0) {
                end[num - 1]--;
                end[num]++;
            }
            // Start new subsequence of length at least 3
            else if (count[num + 1] > 0 && count[num + 2] > 0) {
                count[num + 1]--;
                count[num + 2]--;
                end[num + 2]++;
            } else {
                return false;
            }
        }
        
        return true;
    }
};