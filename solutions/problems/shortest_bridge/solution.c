int n;
int visited[100][100];

// ทิศทาง: บน, ขวา, ล่าง, ซ้าย
int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

// DFS หาเกาะแรกและเก็บขอบไว้
void dfs(int x, int y, int queue[][2], int *qsize, int** grid) {
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (visited[x][y] || grid[x][y] == 0) return;
    
    visited[x][y] = 1;
    
    // ตรวจสอบว่าเป็นขอบหรือไม่ (มีเพื่อนบ้านที่เป็นน้ำ)
    bool isBorder = false;
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
            isBorder = true;  // ขอบของ grid
            break;
        }
        if (grid[nx][ny] == 0) {
            isBorder = true;  // ติดกับน้ำ
            break;
        }
    }
    
    // เก็บเฉพาะขอบ
    if (isBorder) {
        queue[*qsize][0] = x;
        queue[*qsize][1] = y;
        (*qsize)++;
    }
    
    // ไปทุกทิศทาง
    for (int i = 0; i < 4; i++) {
        dfs(x + dir[i][0], y + dir[i][1], queue, qsize, grid);
    }
}

// BFS หาความยาวสะพาน
int bfs(int queue[][2], int qsize, int** grid) {
    int steps = 0;
    int front = 0;
    
    while (front < qsize) {
        int size = qsize - front;
        
        for (int i = 0; i < size; i++) {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;
            
            // ตรวจสอบรอบๆ
            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (visited[nx][ny]) continue;
                
                // เจอเกาะที่สอง
                if (grid[nx][ny] == 1) return steps;
                
                // เป็นน้ำ
                visited[nx][ny] = 1;
                queue[qsize][0] = nx;
                queue[qsize][1] = ny;
                qsize++;
            }
        }
        steps++;
    }
    return -1;
}

int shortestBridge(int** grid, int gridSize, int* gridColSize) {
    n = gridSize;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    
    // 1. หาเกาะแรกด้วย DFS
    int queue[10000][2];
    int qsize = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                dfs(i, j, queue, &qsize, grid);
                // เจอเกาะแรกแล้ว หยุด
                i = n;
                break;
            }
        }
    }
    
    // 2. BFS หาสะพานสั้นที่สุด
    return bfs(queue, qsize, grid);
}