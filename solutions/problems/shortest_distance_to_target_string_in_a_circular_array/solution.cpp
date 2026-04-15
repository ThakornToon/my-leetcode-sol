class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDist = INT_MAX;
        bool found = false;
        
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                found = true;
                int forward = (i - startIndex + n) % n;
                int backward = (startIndex - i + n) % n;
                int dist = min(forward, backward);
                minDist = min(minDist, dist);
            }
        }
        
        return found ? minDist : -1;
    }
};