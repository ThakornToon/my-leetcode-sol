class Solution {
private:
    const int MOD = 1000000007;
    int m, n;
    vector<vector<int>> appleCount;  // จำนวนแอปเปิ้ลในส่วน (row..m-1, col..n-1)
    vector<vector<vector<int>>> memo; // dp[row][col][k]

    // คำนวณจำนวนแอปเปิ้ลในแต่ละส่วนย่อย (จากตำแหน่ง (row, col) ไปถึงมุมล่างขวา)
    void computeAppleCount(vector<string>& pizza) {
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        // คำนวณ prefix sum ของแอปเปิ้ล
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int hasApple = (pizza[i][j] == 'A') ? 1 : 0;
                prefix[i + 1][j + 1] = prefix[i + 1][j] + prefix[i][j + 1] 
                                      - prefix[i][j] + hasApple;
            }
        }

        appleCount.assign(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // แอปเปิ้ลในส่วน (i..m-1, j..n-1)
                appleCount[i][j] = prefix[m][n] - prefix[i][n] 
                                 - prefix[m][j] + prefix[i][j];
            }
        }
    }

    // ตรวจสอบว่าการตัดที่ตำแหน่ง r (แนวนอน) หรือ c (แนวตั้ง) ทำให้ส่วนที่ตัดออกมามีแอปเปิ้ลหรือไม่
    bool hasAppleInTopPart(int row, int col, int cutRow) {
        // ส่วนบน: (row, col) ถึง (cutRow-1, n-1)
        return appleCount[row][col] - appleCount[cutRow][col] > 0;
    }

    bool hasAppleInLeftPart(int row, int col, int cutCol) {
        // ส่วนซ้าย: (row, col) ถึง (m-1, cutCol-1)
        return appleCount[row][col] - appleCount[row][cutCol] > 0;
    }

    // หาจำนวนวิธีตัดแนวนอนทั้งหมด
    long long tryHorizontalCuts(int row, int col, int k) {
        long long total = 0;
        for (int r = row + 1; r < m; r++) {
            if (hasAppleInTopPart(row, col, r)) {
                total = (total + dfs(r, col, k - 1)) % MOD;
            }
        }
        return total;
    }

    // หาจำนวนวิธีตัดแนวตั้งทั้งหมด
    long long tryVerticalCuts(int row, int col, int k) {
        long long total = 0;
        for (int c = col + 1; c < n; c++) {
            if (hasAppleInLeftPart(row, col, c)) {
                total = (total + dfs(row, c, k - 1)) % MOD;
            }
        }
        return total;
    }

    // DFS + Memoization (Recursive DP)
    int dfs(int row, int col, int k) {
        // base case 1: ใช้ memo
        if (memo[row][col][k] != -1) {
            return memo[row][col][k];
        }
        
        // base case 2: ไม่มีแอปเปิ้ลในส่วนนี้
        if (appleCount[row][col] == 0) {
            return memo[row][col][k] = 0;
        }
        
        // base case 3: ต้องการ 1 ชิ้น -> มีแอปเปิ้ลแล้วก็ตัดได้ 1 วิธี
        if (k == 1) {
            return memo[row][col][k] = 1;
        }
        
        // รวมวิธีจากการลองตัดแนวนอนและแนวตั้งที่ตำแหน่งต่างๆ
        long long total = tryHorizontalCuts(row, col, k) 
                        + tryVerticalCuts(row, col, k);
        
        return memo[row][col][k] = total % MOD;
    }
    
public:
    int ways(vector<string>& pizza, int k) {
        m = pizza.size();
        n = pizza[0].size();
        
        // ขั้นตอนที่ 1: คำนวณจำนวนแอปเปิ้ลในแต่ละส่วน
        computeAppleCount(pizza);
        
        // ขั้นตอนที่ 2: สร้าง memo table
        memo.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        
        // ขั้นตอนที่ 3: เริ่ม DFS จากมุมบนซ้าย
        return dfs(0, 0, k);
    }
};