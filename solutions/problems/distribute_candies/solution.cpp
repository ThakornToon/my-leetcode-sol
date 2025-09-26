class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> uniqueTypes;
        int n = candyType.size();
        
        for (int candy : candyType) {
            uniqueTypes.insert(candy);
            if (uniqueTypes.size() >= n / 2) {
                return n / 2;
            }
        }
        
        return uniqueTypes.size();
    }
};