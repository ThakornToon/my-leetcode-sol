class Solution {
private:
    vector<int> result;
    vector<int> used;
    
    bool backtrack(int pos, int n) {
        // ถ้าเติมครบทุกตำแหน่งแล้ว
        if (pos == 2 * n - 1) {
            return true;
        }
        
        // ถ้าตำแหน่งนี้ถูกเติมแล้ว ให้ข้าม
        if (result[pos] != 0) {
            return backtrack(pos + 1, n);
        }
        
        // ลองใส่ตัวเลขจากมากไปน้อย (Greedy)
        for (int num = n; num >= 1; num--) {
            // ถ้าใช้ตัวเลขนี้ครบ 2 ครั้งแล้ว
            if (used[num] == 2) continue;
            
            // กรณี num = 1: วางได้แค่ครั้งเดียว
            if (num == 1) {
                result[pos] = num;
                used[num]++;
                
                if (backtrack(pos + 1, n)) {
                    return true;
                }
                
                // backtrack
                // 3,2,_,3,_ แบบนี้ไม่ได้ ต้องลอง 3,1,_,3,_
                result[pos] = 0;
                used[num]--;
            } 
            // กรณี num > 1: ต้องวางสองครั้ง ห่างกัน num ตำแหน่ง
            else {
                int nextPos = pos + num;
                // ตรวจสอบว่าตำแหน่งถัดไปอยู่ในขอบเขตและว่าง
                if (nextPos < 2 * n - 1 && result[nextPos] == 0) {
                    result[pos] = num;
                    result[nextPos] = num;
                    used[num] += 2;
                    
                    if (backtrack(pos + 1, n)) {
                        return true;
                    }
                    
                    // backtrack
                    result[pos] = 0;
                    result[nextPos] = 0;
                    used[num] -= 2;
                }
            }
        }
        
        return false;
    }

public:
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        result.assign(size, 0);
        used.assign(n + 1, 0);
        
        backtrack(0, n);
        return result;
    }
};