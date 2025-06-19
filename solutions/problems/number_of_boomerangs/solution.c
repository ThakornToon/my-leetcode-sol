int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize) {
    int result = 0;
    
    // สร้าง hash map อย่างง่าย (ใช้ array และ linear probing)
    int* dists = (int*)malloc(pointsSize * sizeof(int));
    int* counts = (int*)malloc(pointsSize * sizeof(int));
    
    for (int i = 0; i < pointsSize; i++) {
        int mapSize = 0;
        
        for (int j = 0; j < pointsSize; j++) {
            int dx = points[i][0] - points[j][0];
            int dy = points[i][1] - points[j][1];
            int dist = dx*dx + dy*dy;
            
            // ค้นหาใน map
            int k;
            for (k = 0; k < mapSize; k++) {
                if (dists[k] == dist) {
                    counts[k]++;
                    break;
                }
            }
            if (k == mapSize) { // ไม่พบ ให้เพิ่มค่านั้นลงไปใน map
                dists[mapSize] = dist;
                counts[mapSize] = 1;
                mapSize++;
            }
        }
        
        for (int k = 0; k < mapSize; k++) {
            result += counts[k] * (counts[k] - 1);
        }
    }
    
    free(dists);
    free(counts);
    return result;
}