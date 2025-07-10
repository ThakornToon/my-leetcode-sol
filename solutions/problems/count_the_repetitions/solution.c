typedef struct {
    int s1_count;
    int s2_count;
} MemoEntry;

int getMaxRepetitions(char* s1, int n1, char* s2, int n2) {
    MemoEntry memo[100] = {0}; // สร้าง memo array
    int s1_cnt = 0, s2_cnt = 0;
    int j = 0; // index สำหรับ s2
    
    while (s1_cnt < n1) {
        // ตรวจสอบทุกตัวอักษรใน s1
        for (int i = 0; s1[i] != '\0'; i++) {
            if (s1[i] == s2[j]) {
                j++;
                // ถ้าสร้าง s2 ได้ครบ 1 ครั้ง
                if (s2[j] == '\0') {
                    j = 0;
                    s2_cnt++;
                }
            }
        }
        s1_cnt++;
        
        // ตรวจสอบ pattern ซ้ำด้วย memoization
        if (memo[j].s1_count != 0) { // j คือ index บน s2 หลังจบการคิดลูปด้านบน
            // คำนวณ pattern ที่ซ้ำ
            int cycle_s1 = s1_cnt - memo[j].s1_count; // เมื่อพบการทำซ้ำมีระยะห่างจำนวนรอบ s1 เท่าไร
            int cycle_s2 = s2_cnt - memo[j].s2_count; // เมื่อพบการทำซ้ำมีระยะห่างจำนวนรอบ s2 เท่าไร
            
            // ข้ามการคำนวณส่วนที่ซ้ำ
            int remaining_cycles = (n1 - s1_cnt) / cycle_s1; // รอบ s1 ที่เหลือ
            s1_cnt += remaining_cycles * cycle_s1;
            s2_cnt += remaining_cycles * cycle_s2;
            
      
        } else {
            // บันทึกสถานะปัจจุบันลง memo
            memo[j].s1_count = s1_cnt;
            memo[j].s2_count = s2_cnt;
        }
    }
    
    return s2_cnt / n2;
}