typedef struct {
    int x, y;
} Point;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    // Directions: up, down, left, right
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Queue for BFS
    Point* queue = malloc(m * n * sizeof(Point));
    int front = 0, rear = 0;
    
    int freshCount = 0;
    int minutes = 0;
    
    // Initialize: count fresh oranges and enqueue rotten ones
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                freshCount++;
            } else if (grid[i][j] == 2) {
                queue[rear].x = i;
                queue[rear].y = j;
                rear++;
            }
        }
    }
    
    // If no fresh oranges initially
    if (freshCount == 0) return 0;
    
    // BFS
    while (front < rear && freshCount > 0) {
        int size = rear - front;  // Number of oranges at current minute
        
        for (int i = 0; i < size; i++) {
            Point current = queue[front++];
            
            // Check all 4 directions
            for (int d = 0; d < 4; d++) {
                int nx = current.x + dirs[d][0];
                int ny = current.y + dirs[d][1];
                
                // Check bounds and if it's a fresh orange
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    // Make it rotten
                    grid[nx][ny] = 2;
                    freshCount--;
                    
                    // Add to queue
                    queue[rear].x = nx;
                    queue[rear].y = ny;
                    rear++;
                }
            }
        }
        
        minutes++;
    }
    
    free(queue);
    
    return freshCount == 0 ? minutes : -1;
}