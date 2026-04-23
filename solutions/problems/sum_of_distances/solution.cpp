class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> result(n, 0);
        
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }
        
        for (auto& [val, indices] : groups) {
            int m = indices.size();
            if (m == 1) continue;
            
            // Prefix sum of indices
            vector<long long> prefix(m, 0);
            prefix[0] = indices[0];
            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + indices[i];
            }
            
            // Total sum of indices
            long long total = prefix[m - 1];
            
            for (int i = 0; i < m; i++) {
                long long leftCount = i;
                long long rightCount = m - i - 1;
                long long leftSum = (i == 0) ? 0 : prefix[i - 1];
                long long rightSum = total - prefix[i];
                
                result[indices[i]] = (leftCount * indices[i] - leftSum) + 
                                     (rightSum - rightCount * indices[i]);
            }
        }
        
        return result;
    }
};