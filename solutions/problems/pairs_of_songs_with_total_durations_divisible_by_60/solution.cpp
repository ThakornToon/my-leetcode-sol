class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> count(60, 0);
        int pairs = 0;
        
        for (int t : time) {
            int rem = t % 60;
            int complement = (60 - rem) % 60;
            
            pairs += count[complement];
            count[rem]++;
        }
        
        return pairs;
    }
};