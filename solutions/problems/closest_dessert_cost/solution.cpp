class Solution {
private:
    void dfs(vector<int>& toppings, int idx, int currentSum, vector<int>& sums) {
        if (idx == toppings.size()) {
            sums.push_back(currentSum);
            return;
        }
        
        for (int i = 0; i <= 2; i++) {
            dfs(toppings, idx + 1, currentSum + i * toppings[idx], sums);
        }
    }

public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        vector<int> toppingSums;
        dfs(toppingCosts, 0, 0, toppingSums);
        sort(toppingSums.begin(), toppingSums.end());
        
        int closest = INT_MAX;
        int minDiff = INT_MAX;
        
        for (int base : baseCosts) {
            for (int toppingSum : toppingSums) {
                int total = base + toppingSum;
                int diff = abs(total - target);
                
                if (diff < minDiff || (diff == minDiff && total < closest)) {
                    minDiff = diff;
                    closest = total;
                }
                
                // pruning: ถ้า total > target และ diff เริ่มเพิ่ม
                if (total > target) break;
            }
        }
        
        return closest;
    }
};