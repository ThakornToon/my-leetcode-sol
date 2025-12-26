#define MAX_N 100

typedef struct {
    int x, y;
} Point;

int maxDistance(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    
    Point queue[MAX_N * MAX_N];
    int front = 0, rear = 0;
    
    // เพิ่มจุดที่เป็นที่ดินทั้งหมดเข้า queue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                queue[rear].x = i;
                queue[rear].y = j;
                rear++;
            }
        }
    }
    
    // ตรวจสอบกรณีพิเศษ
    if (rear == 0 || rear == n * n) {
        return -1;
    }
    
    int maxDist = -1;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // BFS
    while (front < rear) {
        int levelSize = rear - front;
        maxDist++;
        
        for (int i = 0; i < levelSize; i++) {
            Point current = queue[front++];
            
            for (int d = 0; d < 4; d++) {
                int nx = current.x + directions[d][0];
                int ny = current.y + directions[d][1];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;  // ทำเครื่องหมายว่าเยือนแล้ว
                    queue[rear].x = nx;
                    queue[rear].y = ny;
                    rear++;
                }
            }
        }
    }
    
    return maxDist;
}