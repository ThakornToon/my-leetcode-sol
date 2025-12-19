int videoStitching(int** clips, int clipsSize, int* clipsColSize, int time) {
    // สร้าง array สำหรับเก็บจุดสิ้นสุดสูงสุดที่เริ่มจากเวลา i
    int* max_end = (int*)calloc(time + 1, sizeof(int));
    
    // เก็บ max_end สำหรับแต่ละ start time
    for (int i = 0; i < clipsSize; i++) {
        int start = clips[i][0];
        int end = clips[i][1];
        
        if (start <= time) {
            if (end > max_end[start]) {
                max_end[start] = end;
            }
        }
    }
    
    // Greedy algorithm
    int current_end = 0;   // จุดสิ้นสุดที่ครอบคลุมได้ปัจจุบัน
    int next_end = 0;      // จุดสิ้นสุดที่ไกลที่สุดที่เป็นไปได้ใน step ถัดไป
    int count = 0;         // จำนวนคลิปที่ใช้
    
    for (int i = 0; i <= time; i++) {
        // อัปเดต next_end ถ้าเจอคลิปที่ดีกว่า
        if (max_end[i] > next_end) {
            next_end = max_end[i];
        }
        
        // ถ้าถึงจุดสิ้นสุดปัจจุบัน ต้องเลือกคลิปใหม่
        if (i == current_end) {
            // ถ้าไม่สามารถไปต่อได้
            if (next_end <= current_end) {
                return -1;
            }
            
            count++;
            current_end = next_end;
            
            // ถ้าครอบคลุมถึง time แล้ว
            if (current_end >= time) {
                break;
            }
        }
    }
    
    free(max_end);
    return (current_end >= time) ? count : -1;
}