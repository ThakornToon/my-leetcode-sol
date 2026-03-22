/*
90°: new[i][j] = mat[n-1-j][i]
180°: new[i][j] = mat[n-1-i][n-1-j]
270°: new[i][j] = mat[j][n-1-i]
*/

// ฟังก์ชันเปรียบเทียบ matrix
bool isEqual(int** mat, int** target, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != target[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// ฟังก์ชันหมุน 90 องศา (สร้าง matrix ใหม่)
int** rotate90(int** mat, int n) {
    int** rotated = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        rotated[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            rotated[i][j] = mat[n - 1 - j][i];
        }
    }
    return rotated;
}

// ฟังก์ชันหมุน 180 องศา
int** rotate180(int** mat, int n) {
    int** rotated = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        rotated[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            rotated[i][j] = mat[n - 1 - i][n - 1 - j];
        }
    }
    return rotated;
}

// ฟังก์ชันหมุน 270 องศา
int** rotate270(int** mat, int n) {
    int** rotated = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        rotated[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            rotated[i][j] = mat[j][n - 1 - i];
        }
    }
    return rotated;
}

bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
    int n = matSize;
    
    // ตรวจสอบ 0°
    if (isEqual(mat, target, n)) {
        return true;
    }
    
    // ตรวจสอบ 90°
    int** rot90 = rotate90(mat, n);
    if (isEqual(rot90, target, n)) {
        for (int i = 0; i < n; i++) free(rot90[i]);
        free(rot90);
        return true;
    }
    for (int i = 0; i < n; i++) free(rot90[i]);
    free(rot90);
    
    // ตรวจสอบ 180°
    int** rot180 = rotate180(mat, n);
    if (isEqual(rot180, target, n)) {
        for (int i = 0; i < n; i++) free(rot180[i]);
        free(rot180);
        return true;
    }
    for (int i = 0; i < n; i++) free(rot180[i]);
    free(rot180);
    
    // ตรวจสอบ 270°
    int** rot270 = rotate270(mat, n);
    if (isEqual(rot270, target, n)) {
        for (int i = 0; i < n; i++) free(rot270[i]);
        free(rot270);
        return true;
    }
    for (int i = 0; i < n; i++) free(rot270[i]);
    free(rot270);
    
    return false;
}