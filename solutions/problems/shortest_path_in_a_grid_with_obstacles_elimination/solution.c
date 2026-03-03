#define MAX 40  // ขนาดสูงสุดของ grid (ตามโจทย์)

// โครงสร้างสำหรับ queue
typedef struct {
    int row;
    int col;
    int k;      // จำนวน obstacle ที่เหลือ
    int dist;   // ระยะทาง
} State;

int shortestPath(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];
    
    // ถ้าจุดเริ่มต้นและจุดหมายเป็นจุดเดียวกัน
    if (m == 1 && n == 1) return 0;
    
    // visited[row][col][k] = true ถ้าเคยเยือน state นี้แล้ว
    bool*** visited = (bool***)malloc(m * sizeof(bool**));
    for (int i = 0; i < m; i++) {
        visited[i] = (bool**)malloc(n * sizeof(bool*));
        for (int j = 0; j < n; j++) {
            visited[i][j] = (bool*)calloc(k + 1, sizeof(bool));
        }
    }
    
    // queue สำหรับ BFS
    State queue[MAX * MAX * (k + 1)];
    int front = 0, rear = 0;
    
    // เริ่มต้นที่ (0,0) ด้วย k เดิม
    queue[rear++] = (State){0, 0, k, 0};
    visited[0][0][k] = true;
    
    // ทิศทางการเคลื่อนที่
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (front < rear) {
        State current = queue[front++];
        
        // ลองเคลื่อนที่ไป 4 ทิศทาง
        for (int d = 0; d < 4; d++) {
            int nr = current.row + dirs[d][0];
            int nc = current.col + dirs[d][1];
            
            // ตรวจสอบขอบเขต
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            
            int newK = current.k;
            
            // ถ้าเป็น obstacle
            if (grid[nr][nc] == 1) {
                if (newK == 0) continue;  // ลบไม่ได้
                newK--;  // ลบ obstacle นี้
            }
            
            // ถ้าไม่เคยเยือน state นี้
            if (!visited[nr][nc][newK]) {
                // ถ้าถึงจุดหมาย
                if (nr == m - 1 && nc == n - 1) {
                    // คืนหน่วยความจำก่อน return
                    for (int i = 0; i < m; i++) {
                        for (int j = 0; j < n; j++) {
                            free(visited[i][j]);
                        }
                        free(visited[i]);
                    }
                    free(visited);
                    
                    return current.dist + 1;
                }
                
                visited[nr][nc][newK] = true;
                queue[rear++] = (State){nr, nc, newK, current.dist + 1};
            }
        }
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            free(visited[i][j]);
        }
        free(visited[i]);
    }
    free(visited);
    
    return -1;  // ไม่มี
}