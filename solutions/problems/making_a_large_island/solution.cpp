class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> islandId(n, vector<int>(n, -1));
        unordered_map<int, int> islandSize;
        int id = 0;
        
        // Step 1: Find all islands and their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && islandId[i][j] == -1) {
                    int size = dfs(grid, islandId, i, j, id);
                    islandSize[id] = size;
                    id++;
                }
            }
        }

        // If no water cells, return the largest island
        if (islandSize.empty()) return 1;
        if (id == 1 && islandSize[0] == n * n) return n * n;
        
        int maxArea = 0;
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        // Step 2: Check every water cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (islandId[i][j] == -1) {
                    unordered_set<int> connectedIslands;
                    int area = 1; // The converted cell itself
                    
                    // Check all 4 directions
                    for (auto [dx, dy] : directions) {
                        int x = i + dx, y = j + dy;
                        if (x >= 0 && x < n && y >= 0 && y < n && islandId[x][y] != -1) {
                            int neighborId = islandId[x][y];
                            if (connectedIslands.insert(neighborId).second) {
                                area += islandSize[neighborId];
                            }
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

private:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& islandId, int i, int j, int id) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || islandId[i][j] != -1) {
            return 0;
        }
        
        islandId[i][j] = id;
        int size = 1;
        
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for (auto [dx, dy] : directions) {
            size += dfs(grid, islandId, i + dx, j + dy, id);
        }
        
        return size;
    }
};