// ฟังก์ชันสำหรับเปรียบเทียบ (ใช้กับ qsort)
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// ฟังก์ชันหาค่าต่ำสุด
int min(int a, int b) {
    return a < b ? a : b;
}

int makeArrayIncreasing(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    // เรียง arr2
    qsort(arr2, arr2Size, sizeof(int), compare);
    
    // ลบค่าซ้ำใน arr2
    int uniqueSize = 0;
    for (int i = 0; i < arr2Size; i++) {
        if (i == 0 || arr2[i] != arr2[i-1]) {
            arr2[uniqueSize++] = arr2[i];
        }
    }
    arr2Size = uniqueSize;
    
    int n = arr1Size;
    int m = arr2Size;
    
    // สร้าง dp array n x (m+1)
    // dp[i][j] = min ops ที่ทำให้ arr1[0..i] strictly increasing 
    // โดย arr1[i] = arr2[j] (หรือไม่เปลี่ยนถ้า j == m)
    // j = m หมายถึงไม่แทนที่ (ใช้ค่าเดิมจาก arr1[i])
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc((m + 1) * sizeof(int));
        for (int j = 0; j <= m; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    
    // Base case
    dp[0][m] = 0;  // ไม่เปลี่ยนค่าแรก
    for (int j = 0; j < m; j++) {
        dp[0][j] = 1;  // เปลี่ยนค่าแรกเป็น arr2[j]
    }
    
    // สร้าง array สำหรับ prefix minimum
    int* prefixMin = (int*)malloc(m * sizeof(int));
    
    for (int i = 1; i < n; i++) {
        // คำนวณ prefix minimum สำหรับ dp[i-1][k]
        // prefixMin[j] = min(dp[i-1][k]) สำหรับ k <= j หากรณีดีที่สุดก่อนหน้าเพื่อลดการคิด
        int minSoFar = INT_MAX;
        for (int j = 0; j < m; j++) {
            minSoFar = min(minSoFar, dp[i-1][j]);
            prefixMin[j] = minSoFar;
        }
        
        for (int j = 0; j <= m; j++) {
            int currentVal = (j == m) ? arr1[i-1] : arr2[j];
            
            // กรณีใช้ค่าเดิมจาก arr1 (j == m)
            if (j == m) {
                // จากค่าก่อนหน้าที่ไม่เปลี่ยน
                if (arr1[i] > arr1[i-1]) {
                    dp[i][m] = min(dp[i][m], dp[i-1][m]);
                }
                // จากค่าก่อนหน้าที่เปลี่ยนเป็น arr2[k]
                for (int j = 0; j < m; j++) {
                    if (arr1[i] > arr2[j] && dp[i-1][j] != INT_MAX) {
                        dp[i][m] = min(dp[i][m], dp[i-1][j]);
                    }
                }
            }
            
            // กรณีเปลี่ยนเป็น arr2[j] (j < m)
            if (j < m) {
                // จากค่าก่อนหน้าที่ไม่เปลี่ยน
                if (arr2[j] > arr1[i-1] && dp[i-1][m] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], dp[i-1][m] + 1);
                }
                
                // จากค่าก่อนหน้าที่เปลี่ยนเป็น arr2[k] ที่ < arr2[j]
                if (j > 0 && prefixMin[j - 1] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], prefixMin[j - 1] + 1);
                }
            }
        }
    }
    
    // หาคำตอบ
    int result = INT_MAX;
    for (int j = 0; j <= m; j++) {
        result = min(result, dp[n - 1][j]);
    }
    
    // ทำความจำ
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    free(prefixMin);
    
    return result >= INT_MAX ? -1 : result;
}