class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> rows, cols, diag1, diag2;
        unordered_set<long long> lampSet;
        
        // Helper function to encode position
        auto encode = [&](int r, int c) -> long long {
            return (long long)r * n + c;
        };
        
        // Add all lamps
        for (const auto& lamp : lamps) {
            int r = lamp[0], c = lamp[1];
            long long key = encode(r, c);
            
            if (!lampSet.count(key)) {
                lampSet.insert(key);
                rows[r]++;
                cols[c]++;
                diag1[r - c]++;
                diag2[r + c]++;
            }
        }
        
        // Directions for 3x3 block
        vector<pair<int, int>> dirs = {
            {0,0}, {0,1}, {0,-1},
            {1,0}, {1,1}, {1,-1},
            {-1,0}, {-1,1}, {-1,-1}
        };
        
        vector<int> result;
        
        // Process queries
        for (const auto& query : queries) {
            int r = query[0], c = query[1];
            
            // Check illumination
            bool illuminated = rows[r] > 0 || cols[c] > 0 || 
                               diag1[r - c] > 0 || diag2[r + c] > 0;
            result.push_back(illuminated ? 1 : 0);
            
            // Turn off lamps in 3x3 block
            for (const auto& dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    long long key = encode(nr, nc);
                    
                    if (lampSet.count(key)) {
                        lampSet.erase(key);
                        rows[nr]--;
                        cols[nc]--;
                        diag1[nr - nc]--;
                        diag2[nr + nc]--;
                    }
                }
            }
        }
        
        return result;
    }
};