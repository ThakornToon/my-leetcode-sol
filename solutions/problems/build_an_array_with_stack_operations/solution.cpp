class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int num = 1;
        
        for (int val : target) {
            while (num < val) {
                result.push_back("Push");
                result.push_back("Pop");
                num++;
            }
            result.push_back("Push");
            num++;
        }

        return result;
    }
};