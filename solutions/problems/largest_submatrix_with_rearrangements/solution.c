#define MAX(a, b) ((a) > (b) ? (a) : (b))

// ฟังก์ชันเปรียบเทียบสำหรับ qsort (เรียงจากมากไปน้อย)
int cmp(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int maxArea = 0;
    
    // คำนวณความสูงสะสม
    for (int i = 0; i < m; i++) {
        // อัปเดตความสูง
        for (int j = 0; j < n; j++) {
            if (i > 0 && matrix[i][j] == 1) {
                matrix[i][j] += matrix[i - 1][j];
            }
        }
        
        // สร้าง array ของความสูงในแถวนี้
        int* heights = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            heights[j] = matrix[i][j];
        }
        
        // เรียงลำดับจากมากไปน้อย
        qsort(heights, n, sizeof(int), cmp);
        
        // คำนวณพื้นที่ที่เป็นไปได้
        for (int j = 0; j < n; j++) {
            if (heights[j] == 0) break;
            int area = heights[j] * (j + 1);
            maxArea = MAX(maxArea, area);
        }
        
        free(heights);
    }
    
    return maxArea;
}