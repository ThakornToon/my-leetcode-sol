class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int targetX = target[0], targetY = target[1];
        int myDistance = abs(targetX) + abs(targetY);
        
        for (auto& ghost : ghosts) {
            int ghostDistance = abs(ghost[0] - targetX) + abs(ghost[1] - targetY);
            if (ghostDistance <= myDistance) {
                return false;
            }
        }
        
        return true;
    }
};