typedef struct {
    int r, c, dir;
} State;

bool canMoveRight(int r, int c, int dir, int n, int** grid) {
    if (dir == 0) { // horizontal
        return c + 2 < n && grid[r][c+2] == 0;
    } else { // vertical
        return c + 1 < n && grid[r][c+1] == 0 && grid[r+1][c+1] == 0;
    }
}

bool canMoveDown(int r, int c, int dir, int n, int** grid) {
    if (dir == 0) { // horizontal
        return r + 1 < n && grid[r+1][c] == 0 && grid[r+1][c+1] == 0;
    } else { // vertical
        return r + 2 < n && grid[r+2][c] == 0;
    }
}

bool canRotate(int r, int c, int dir, int n, int** grid) {
    if (r + 1 >= n || c + 1 >= n) {
        return false;
    }
    
    if (dir == 0) { 
        // หมุนตามเข็มนาฬิกา: แนวนอน → แนวตั้ง
        // ต้องมีพื้นที่ว่างใต้ทั้งสองช่อง
        return grid[r+1][c] == 0 && grid[r+1][c+1] == 0;
    } else { 
        // หมุนทวนเข็มนาฬิกา: แนวตั้ง → แนวนอน
        // ต้องมีพื้นที่ว่างทางขวาทั้งสองช่อง
        return grid[r][c+1] == 0 && grid[r+1][c+1] == 0;
    }
}

int minimumMoves(int** grid, int gridSize, int* gridColSize){
    int n = gridSize;
    
    // 3D visited array
    // สถานะ: visited[tail_row][tail_col][direction] เก็บตำแหน่งงหางอละทิศทางของหะว
    // direction: 0 = horizontal, 1 = vertical
    bool visited[n][n][2];
    memset(visited, 0, sizeof(visited));
    
    // Queue for BFS
    State* queue = (State*)malloc(n * n * 2 * sizeof(State));
    int front = 0, rear = 0;
    
    // Start state
    queue[rear++] = (State){0, 0, 0};
    visited[0][0][0] = true;
    
    int steps = 0;
    
    while (front < rear) {
        int size = rear - front;
        
        for (int i = 0; i < size; i++) {
            State current = queue[front++];
            
            // ถึงเป้าหมายรึยัง
            if (current.r == n-1 && current.c == n-2 && current.dir == 0) {
                free(queue);
                return steps;
            }
            
            // Move right
            if (canMoveRight(current.r, current.c, current.dir, n, grid)) {
                State next = {current.r, current.c + 1, current.dir};
                if (!visited[next.r][next.c][next.dir]) {
                    visited[next.r][next.c][next.dir] = true;
                    queue[rear++] = next;
                }
            }
            
            // Move down
            if (canMoveDown(current.r, current.c, current.dir, n, grid)) {
                State next = {current.r + 1, current.c, current.dir};
                if (!visited[next.r][next.c][next.dir]) {
                    visited[next.r][next.c][next.dir] = true;
                    queue[rear++] = next;
                }
            }
            
            // Rotate
            if (canRotate(current.r, current.c, current.dir, n, grid)) {
                State next = {current.r, current.c, 1 - current.dir}; // หมุนลงหรือขึ้น
                if (!visited[next.r][next.c][next.dir]) {
                    visited[next.r][next.c][next.dir] = true;
                    queue[rear++] = next;
                }
            }
        }
        
        steps++;
    }
    
    free(queue);
    return -1;
}