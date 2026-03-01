class Solution {
public:
    int minPartitions(string n) {
        char maxChar = *max_element(n.begin(), n.end());
        return maxChar - '0';
    }
};