class Solution {
private:
    int nextState(int state) {
        int next = 0;
        // ตำแหน่งที่ 0 และ 7 เป็น 0 เสมอ
        for (int i = 1; i < 7; i++) {
            int left = (state >> (i-1)) & 1;
            int right = (state >> (i+1)) & 1;
            if (left == right) {
                next |= (1 << i);
            }
        }
        return next;
    }
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {        
        // แปลงเป็น bitmask
        int state = 0;
        for (int i = 0; i < 8; i++) {
            if (cells[i] == 1) {
                state |= (1 << i);
            }
        }
        
        unordered_map<int, int> seen; // state : day
        vector<int> states; // เก็บ state แต่ละวัน
        
        // Simulate จนพบ cycle
        while (n > 0) {
            if (seen.find(state) != seen.end()) {
                // พบ cycle
                int cycleStart = seen[state];
                int cycleLength = states.size() - cycleStart;
                
                // คำนวณ state สุดท้าย
                int remainingDays = n % cycleLength;
                state = states[cycleStart + remainingDays];
                break;
            }
            
            seen[state] = states.size();
            states.push_back(state);
            
            // คำนวณวันถัดไป
            state = nextState(state);
            n--;
        }
        
        // แปลงกลับเป็น vector
        vector<int> result(8);
        for (int i = 0; i < 8; i++) {
            result[i] = (state >> i) & 1;
        }
        
        return result;
    }
};