/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* bestCoordinate(int** towers, int towersSize, int* towersColSize, int radius, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    int maxQuality = -1;
    int bestX = 0, bestY = 0;
    
    // brute force ทุกจุดในช่วง [0,50]
    for (int x = 0; x <= 50; x++) {
        for (int y = 0; y <= 50; y++) {
            int totalQuality = 0;
            
            // คำนวณ signal จากทุก tower
            for (int i = 0; i < towersSize; i++) {
                int tx = towers[i][0];
                int ty = towers[i][1];
                int q = towers[i][2];
                
                // ระยะทางระหว่าง (x,y) กับ tower
                double dx = x - tx;
                double dy = y - ty;
                double dist = sqrt(dx*dx + dy*dy);
                
                // ใช้ radius แทน q ในการเช็คระยะ!
                if (dist <= radius) {
                    totalQuality += (int)(q / (1 + dist));
                }
            }
            
            // update best point (lexicographically)
            if (totalQuality > maxQuality) {
                maxQuality = totalQuality;
                bestX = x;
                bestY = y;
            }
        }
    }
    
    result[0] = bestX;
    result[1] = bestY;
    return result;
}