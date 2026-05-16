class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        // สร้าง preference rank matrix 
        // rank[x][y] คนที่ x ชอบ y เป็นอันดับที่เท่าไร
        vector<vector<int>> rank(n, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                int friendId = preferences[i][j];
                rank[i][friendId] = j; // อันดับความชอบ (ยิ่งน้อยยิ่งชอบมาก)
            }
            rank[i][i] = n; // ตัวเองไม่มีความชอบ
        }
        
        // สร้าง array ของคู่ที่จับกัน
        vector<int> pair(n);
        for (auto& p : pairs) {
            int x = p[0], y = p[1];
            pair[x] = y;
            pair[y] = x;
        }
        
        int unhappyCount = 0;
        
        // ตรวจสอบแต่ละคน
        for (int x = 0; x < n; x++) {
            int y = pair[x]; // คู่ปัจจุบัน
            
            // ดูเพื่อนทุกคนที่ x ชอบมากกว่า y
            for (int idx = 0; idx < rank[x][y]; idx++) {
                int u = preferences[x][idx]; // u คือคนที่ x ชอบมากกว่า y
                int v = pair[u]; // คู่ของ u
                
                // ตรวจสอบว่า u ชอบ x มากกว่า v หรือไม่
                if (rank[u][x] < rank[u][v]) {
                    unhappyCount++;
                    break; // เจอแค่อันเดียวก็พอ
                }
            }
        }
        
        return unhappyCount;
    }
};