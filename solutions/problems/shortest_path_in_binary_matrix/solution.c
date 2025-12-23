#define MAX_N 100

typedef struct {
    int row;
    int col;
} Point;

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    
    // ถ้าจุดเริ่มต้นหรือจุดปลายเป็น 1 => ไม่มีเส้นทาง
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
        return -1;
    }
    
    // 8 ทิศทาง
    int dirs[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };
    
    // distance matrix เริ่มต้นเป็น -1 (ยังไม่เยี่ยมชม)
    int** dist = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dist[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            dist[i][j] = -1;
        }
    }
    
    // queue สำหรับ BFS
    Point* queue = (Point*)malloc(n * n * sizeof(Point));
    int front = 0, rear = 0;
    
    // เริ่ม BFS จาก (0,0)
    queue[rear++] = (Point){0, 0};
    dist[0][0] = 1;
    
    while (front < rear) {
        Point curr = queue[front++];
        int r = curr.row;
        int c = curr.col;
        
        // ถ้าถึงจุดหมาย
        if (r == n-1 && c == n-1) {
            int result = dist[r][c];
            
            // คืนหน่วยความจำ
            for (int i = 0; i < n; i++) {
                free(dist[i]);
            }
            free(dist);
            free(queue);
            
            return result;
        }
        
        // ตรวจสอบ 8 ทิศทาง
        for (int d = 0; d < 8; d++) {
            int nr = r + dirs[d][0];
            int nc = c + dirs[d][1];
            
            // ตรวจสอบขอบเขตและเงื่อนไข
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && 
                grid[nr][nc] == 0 && dist[nr][nc] == -1) {
                
                dist[nr][nc] = dist[r][c] + 1;
                queue[rear++] = (Point){nr, nc};
            }
        }
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i < n; i++) {
        free(dist[i]);
    }
    free(dist);
    free(queue);
    
    return -1; // ไม่พบเส้นทาง
}