class Solution {
private:
    // bfs หา shortest step จาก (sr, sc) ไป (tr, tc)
    int bfs(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {
        if (sr == tr && sc == tc) return 0;
        int m = forest.size();
        int n = forest[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        q.push({sr, sc});
        visited[sr][sc] = true;
        int steps = 0;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int size = q.size();
            steps++;
            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    
                    if (nr == tr && nc == tc) return steps;
                    
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && forest[nr][nc] != 0) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return -1;
    }

public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        int n = forest[0].size();
        
        vector<vector<int>> paths;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (forest[r][c] > 1) {
                    paths.push_back({forest[r][c], r, c});
                }
            }
        }
        
        sort(paths.begin(), paths.end());
        
        int total_steps = 0;
        int curr_r = 0, curr_c = 0;
        
        // หา step ไปยังต้นไม้จุดต่างๆ จากน้อยไปมาก
        for (auto& path : paths) {
            int target_r = path[1];
            int target_c = path[2];
            
            int steps = bfs(forest, curr_r, curr_c, target_r, target_c);
            if (steps == -1) return -1;
            
            total_steps += steps;
            curr_r = target_r;
            curr_c = target_c;
        }
        
        return total_steps;
    }
};