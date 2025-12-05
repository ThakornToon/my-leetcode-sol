typedef struct {
    int x;
    int y;
} Point;

// ฟังก์ชันเปรียบเทียบสำหรับ qsort เรียง x ก่อนแล้วดู y
int comparePoints(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    
    if (p1->x != p2->x) {
        return p1->x - p2->x;
    }
    return p1->y - p2->y;
}

// Binary Search ตรวจสอบอุปสรรค
bool isObstacleBinary(Point* obstacles, int obstaclesSize, int x, int y) {
    int left = 0, right = obstaclesSize - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (obstacles[mid].x == x && obstacles[mid].y == y) {
            return true;
        }
        
        if (obstacles[mid].x < x || (obstacles[mid].x == x && obstacles[mid].y < y)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}

int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
    // แปลง obstacles เป็น array of Point
    Point* obstaclesP = (Point*)malloc(obstaclesSize * sizeof(Point));
    for (int i = 0; i < obstaclesSize; i++) {
        obstaclesP[i].x = obstacles[i][0];
        obstaclesP[i].y = obstacles[i][1];
    }
    
    // Sort obstacles เพื่อใช้ binary search
    qsort(obstaclesP, obstaclesSize, sizeof(Point), comparePoints);
    
    // ทิศทาง
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    int x = 0, y = 0;
    int direction = 0;
    int maxDist = 0;
    
    for (int i = 0; i < commandsSize; i++) {
        int cmd = commands[i];
        
        if (cmd == -2) {
            direction = (direction + 3) % 4;
        } else if (cmd == -1) {
            direction = (direction + 1) % 4;
        } else {
            for (int step = 0; step < cmd; step++) {
                int nextX = x + dx[direction];
                int nextY = y + dy[direction];
                
                // ตรวจสอบด้วย binary search
                if (isObstacleBinary(obstaclesP, obstaclesSize, nextX, nextY)) {
                    break;
                }
                
                x = nextX;
                y = nextY;
                
                int dist = x * x + y * y;
                if (dist > maxDist) {
                    maxDist = dist;
                }
            }
        }
    }
    
    free(obstacles);
    return maxDist;
}