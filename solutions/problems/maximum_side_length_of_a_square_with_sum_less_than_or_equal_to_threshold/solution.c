#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
    int m = matSize;
    int n = matColSize[0];
    
    // สร้าง 2D prefix sum array เป็นผลรวมของสี่เหลี่ยมจาก (0, 0)
    int** prefix = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        prefix[i] = (int*)calloc(n + 1, sizeof(int));
    }
    
    // คำนวณ prefix sum สี่เหลี่ยม
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] 
                         + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    
    // ฟังก์ชันคำนวณผลรวมสี่เหลี่ยม
    int getSum(int r1, int c1, int side) {
        int r2 = r1 + side;
        int c2 = c1 + side;
        return prefix[r2][c2] - prefix[r1][c2] 
             - prefix[r2][c1] + prefix[r1][c1];
    }
    
    // Binary search บนขนาดด้าน
    int left = 1, right = min(m, n);
    int answer = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        bool found = false;
        
        // ตรวจสอบทุกสี่เหลี่ยมขนาด mid x mid
        for (int i = 0; i + mid <= m; i++) {
            for (int j = 0; j + mid <= n; j++) {
                int sum = getSum(i, j, mid);
                if (sum <= threshold) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        
        if (found) {
            answer = mid;
            left = mid + 1;  // ลองหาขนาดใหญ่กว่า
        } else {
            right = mid - 1;  // ลองหาขนาดเล็กลง
        }
    }
    
    // free memory
    for (int i = 0; i <= m; i++) {
        free(prefix[i]);
    }
    free(prefix);
    
    return answer;
}