class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> amounts(amount + 1, INT_MAX);
        amounts[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && amounts[i - coin] != INT_MAX) {
                    amounts[i] = min(amounts[i], amounts[i - coin] + 1);
                }
            }
        }
        return (amounts[amount] == INT_MAX) ? -1 : amounts[amount];
    }
};