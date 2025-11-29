int largestOverlap(int** img1, int img1Size, int* img1ColSize, int** img2, int img2Size, int* img2ColSize) {
    int n = img1Size;
    int maxOverlap = 0;
    
    for (int dx = -n + 1; dx < n; dx++) {
        for (int dy = -n + 1; dy < n; dy++) {
            int overlap = 0;
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int new_i = i + dx;
                    int new_j = j + dy;
                    
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n) {
                        if (img1[i][j] == 1 && img2[new_i][new_j] == 1) {
                            overlap++;
                        }
                    }
                }
            }
            
            if (overlap > maxOverlap) {
                maxOverlap = overlap;
            }
        }
    }
    
    return maxOverlap;
}