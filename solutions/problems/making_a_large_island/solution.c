#define MAX_N 500

int largestIsland(int** grid, int n, int* gridColSize) {
    int id = 2;  // เริ่มจาก 2 เพราะ 0=น้ำ, 1=เกาะเดิม
    int sizes[MAX_N * MAX_N + 2] = {0};
    int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    // DFS function - ใช้ grid เก็บ ID โดยตรง
    void dfs(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) 
            return;
        
        grid[i][j] = id;  // ใช้ grid เก็บ ID
        sizes[id]++;
        
        for (int k = 0; k < 4; k++) {
            dfs(i + dirs[k][0], j + dirs[k][1]);
        }
    }
    
    // Find islands - ใช้ grid เก็บ ID
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                dfs(i, j);
                id++;
            }
        }
    }
    
    int maxArea = 0;
    for (int i = 2; i < id; i++) {
        if (sizes[i] > maxArea) maxArea = sizes[i];
    }
    
    // Check water cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                int used[4] = {0};
                int count = 0;
                int area = 1;
                
                for (int k = 0; k < 4; k++) {
                    int x = i + dirs[k][0];
                    int y = j + dirs[k][1];
                    
                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] >= 2) {
                        int islandId = grid[x][y];
                        int found = 0;
                        
                        for (int m = 0; m < count; m++) {
                            if (used[m] == islandId) {
                                found = 1;
                                break;
                            }
                        }
                        
                        if (!found) {
                            area += sizes[islandId];
                            used[count++] = islandId;
                        }
                    }
                }
                
                if (area > maxArea) maxArea = area;
            }
        }
    }
    
    return maxArea;
}