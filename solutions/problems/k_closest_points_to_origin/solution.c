/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    int x;
    int y;
    long long dist_sq; // เก็บกำลังสองเพื่อหลีกเลี่ยง sqrt
} Point;

// ฟังก์ชันเปรียบเทียบสำหรับ qsort
int compare(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return (p1->dist_sq > p2->dist_sq) - (p1->dist_sq < p2->dist_sq);
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes) {
    // สร้างอาร์เรย์ของ Point
    Point* arr = (Point*)malloc(pointsSize * sizeof(Point));
    
    for (int i = 0; i < pointsSize; i++) {
        long long x = points[i][0];
        long long y = points[i][1];
        arr[i].x = points[i][0];
        arr[i].y = points[i][1];
        arr[i].dist_sq = x * x + y * y; // ใช้กำลังสองแทน sqrt
    }
    
    // เรียงลำดับตามระยะทาง
    qsort(arr, pointsSize, sizeof(Point), compare);
    
    // จองหน่วยความจำสำหรับผลลัพธ์
    int** result = (int**)malloc(k * sizeof(int*));
    *returnColumnSizes = (int*)malloc(k * sizeof(int));
    *returnSize = k;
    
    for (int i = 0; i < k; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        result[i][0] = arr[i].x;
        result[i][1] = arr[i].y;
        (*returnColumnSizes)[i] = 2;
    }
    
    free(arr);
    return result;
}