#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int result;  // เก็บผลลัพธ์ที่ดีที่สุดที่เจอ

// ตรวจสอบว่าสามารถปูสี่เหลี่ยมขนาด size ที่ตำแหน่ง (x,y) ได้หรือไม่
int canPlace(int** grid, int n, int m, int x, int y, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[x + i][y + j] == 1) {
                return 0;
            }
        }
    }
    
    return 1;
}

// ปูสี่เหลี่ยมที่ตำแหน่ง (x,y) ขนาด size
void placeSquare(int** grid, int x, int y, int size, int value) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[x + i][y + j] = value;
        }
    }
}

// หาตำแหน่งว่างซ้ายบนสุด
int findEmpty(int** grid, int n, int m, int* x, int* y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                *x = i;
                *y = j;
                return 1;
            }
        }
    }
    return 0;
}

// DFS + Backtracking
void dfs(int** grid, int n, int m, int count) {
    // ถ้านับได้มากกว่าผลลัพธ์ที่ดีที่สุดแล้ว ให้หยุด
    if (count >= result) {
        return;
    }
    
    int x, y;  // ตำแหน่งที่จะปู
    if (!findEmpty(grid, n, m, &x, &y)) {
        // ปูหมดแล้ว
        result = min(result, count);
        return;
    }
    
    // พยายามปูด้วยสี่เหลี่ยมขนาดใหญ่ที่สุดที่เป็นไปได้
    int maxSize = min(n - x, m - y);
    
    // ลองจากขนาดใหญ่ไปเล็ก
    for (int size = maxSize; size >= 1; size--) {
        if (canPlace(grid, n, m, x, y, size)) {
            placeSquare(grid, x, y, size, 1);
            dfs(grid, n, m, count + 1);
            placeSquare(grid, x, y, size, 0);  // backtrack
        }
    }
}

int tilingRectangle(int n, int m) {
    if (n == m) return 1;
    
    // ทำให้ n เป็นด้านสั้นเสมอ (เพื่อลดกรณี)
    if (n > m) {
        int temp = n;
        n = m;
        m = temp;
    }
    
    // สร้าง grid ขนาด n * m
    int** grid = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        grid[i] = (int*)calloc(m, sizeof(int));
    }
    
    result = INT_MAX;
    dfs(grid, n, m, 0);
    
    // คืนหน่วยความจำ
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);
    
    return result;
}