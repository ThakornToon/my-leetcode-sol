class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> stones = {a, b, c};
        sort(stones.begin(), stones.end());
        
        int x = stones[0];
        int y = stones[1];
        int z = stones[2];
        
        vector<int> result(2);
        
        // Minimum moves
        if (z - x == 2) {  // Already consecutive
            result[0] = 0;
        } else if (y - x <= 2 || z - y <= 2) {
            // Can move one stone to fill the gap
            result[0] = 1;
        } else {
            result[0] = 2;
        }
        
        // Maximum moves
        // Each move can reduce the gap by 1
        result[1] = (z - x - 2);
        
        return result;
    }
};