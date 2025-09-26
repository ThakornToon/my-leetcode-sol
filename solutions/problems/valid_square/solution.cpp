class Solution {
public:
    int calculateDistance(vector<int>& p1, vector<int>& p2) {
        int dx = p1[0] - p2[0];
        int dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        vector<int> dists;
        
        // Calculate all 6 distances
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                int dist = calculateDistance(points[i], points[j]);
                if (dist == 0) return false; // Reject duplicate points
                dists.push_back(dist);
            }
        }
        
        // Sort distances
        sort(dists.begin(), dists.end());
        
        // For a valid square:
        // - First 4 should be equal (sides)
        // - Last 2 should be equal (diagonals)
        // - Diagonal should be 2 * side (Pythagorean theorem)
        return (dists[0] == dists[1] && dists[1] == dists[2] && dists[2] == dists[3] && dists[4] == dists[5] && 
                dists[0] * 2 == dists[4]);
    }
};