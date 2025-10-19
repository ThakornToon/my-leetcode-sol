#define MAX_STOPS 1000000
#define MAX_ROUTES 500

int numBusesToDestination(int** routes, int routesSize, int* routesColSize, int source, int target) {
    // กรณีเริ่มต้นกับปลายทางเดียวกัน
    if (source == target) return 0;
    
    // สร้าง array สำหรับเก็บว่าป้ายนี้มีสายรถเมล์อะไรบ้าง
    int* stopRoutes[MAX_STOPS] = {0};
    int stopRoutesSize[MAX_STOPS] = {0};
    
    // นับจำนวนป้ายสูงสุด
    int maxStop = 0;
    for (int i = 0; i < routesSize; i++) {
        for (int j = 0; j < routesColSize[i]; j++) {
            int stop = routes[i][j];
            if (stop > maxStop) maxStop = stop;
        }
    }
    
    // จอง memory สำหรับเก็บข้อมูลป้าย
    for (int i = 0; i <= maxStop; i++) {
        stopRoutes[i] = (int*)malloc(MAX_ROUTES * sizeof(int));
    }
    
    // ใส่ข้อมูลสายรถเมล์ให้แต่ละป้าย
    for (int i = 0; i < routesSize; i++) {
        for (int j = 0; j < routesColSize[i]; j++) {
            int stop = routes[i][j];
            stopRoutes[stop][stopRoutesSize[stop]++] = i;
        }
    }
    
    // BFS
    int* queue = (int*)malloc(routesSize * sizeof(int));
    bool* visited = (bool*)calloc(routesSize, sizeof(bool));
    int front = 0, rear = 0;
    
    // เริ่มจากสายทั้งหมดที่ผ่าน source
    for (int i = 0; i < stopRoutesSize[source]; i++) {
        int route = stopRoutes[source][i];
        if (!visited[route]) {
            queue[rear++] = route;
            visited[route] = true;
        }
    }
    
    int buses = 1;
    
    while (front < rear) {
        int currentSize = rear - front;
        
        for (int i = 0; i < currentSize; i++) {
            int currentRoute = queue[front++]; // คันปัจจุบัน
            
            // ตรวจสอบทุกป้ายในสายนี้
            for (int j = 0; j < routesColSize[currentRoute]; j++) {
                int stop = routes[currentRoute][j];
                
                // ถ้าพบป้ายปลายทาง
                if (stop == target) {
                    // ทำความสะอาด memory
                    for (int k = 0; k <= maxStop; k++) {
                        free(stopRoutes[k]);
                    }
                    free(queue);
                    free(visited);
                    return buses;
                }
                
                // ดูสายอื่นๆ ที่ผ่านป้ายนี้
                for (int k = 0; k < stopRoutesSize[stop]; k++) {
                    int nextRoute = stopRoutes[stop][k];
                    if (!visited[nextRoute]) {
                        visited[nextRoute] = true;
                        queue[rear++] = nextRoute;
                    }
                }
            }
        }
        buses++;
    }
    
    // ทำความสะอาด memory
    for (int i = 0; i <= maxStop; i++) {
        free(stopRoutes[i]);
    }
    free(queue);
    free(visited);
    
    return -1;
}