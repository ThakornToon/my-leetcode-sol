int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int totalTime = 0;
    
    for (int i = 0; i < pointsSize - 1; i++) {
        int x1 = points[i][0];
        int y1 = points[i][1];
        int x2 = points[i+1][0];
        int y2 = points[i+1][1];
        
        // คำนวณผลต่างสัมบูรณ์
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        
        // เวลาระหว่างจุดคือ max(dx, dy)
        totalTime += (dx > dy) ? dx : dy;
    }
    
    return totalTime;
}