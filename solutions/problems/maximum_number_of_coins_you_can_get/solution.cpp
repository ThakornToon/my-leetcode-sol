class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // sort จากมากไปน้อย
        sort(piles.begin(), piles.end(), greater<int>());
        int total = 0;
        
        // คุณจะได้ piles[1], piles[3], piles[5], ...
        for (int i = 1, count = 0; i < piles.size() - count; i += 2, count++) {
            total += piles[i];
        }
        
        return total;
    }
};