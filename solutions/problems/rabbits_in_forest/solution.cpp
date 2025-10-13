class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        
        // นับความถี่
        for (int ans : answers) {
            count[ans]++;
        }
        
        int total = 0;
        for (auto& [k, cnt] : count) {
            int group_size = k + 1;
            int groups = (cnt + group_size - 1) / group_size;
            total += groups * group_size;
        }
        
        return total;
    }
};