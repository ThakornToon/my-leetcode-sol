class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int give = 1;
        
        while (candies > 0) {
            int current_give = std::min(give, candies);
            result[(give - 1) % num_people] += current_give;
            candies -= current_give;
            give++;
        }
        
        return result;
    }
};