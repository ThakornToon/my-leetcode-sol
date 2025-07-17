/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    int x, y;
} Point;

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    int m = matSize, n = matColSize[0];
    int** dist = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    *returnSize = m;
    
    for (int i = 0; i < m; i++) {
        dist[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    
    Point* queue = (Point*)malloc((m * n) * sizeof(Point));
    int front = 0, rear = 0;
    
    // เก็บตำแหน่งเริ่มต้นของ 0 ทั้งหมด
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;
                queue[rear++] = (Point){i, j};
            }
        }
    }
    
    // ทิศทางสำหรับเคลื่อนที่
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (front < rear) {
        Point curr = queue[front++];
        
        for (int k = 0; k < 4; k++) {
            int x = curr.x + dirs[k][0];
            int y = curr.y + dirs[k][1];
            
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (dist[x][y] > dist[curr.x][curr.y] + 1) {
                    dist[x][y] = dist[curr.x][curr.y] + 1;
                    queue[rear++] = (Point){x, y};
                }
            }
        }
    }
    
    free(queue);
    return dist;
}