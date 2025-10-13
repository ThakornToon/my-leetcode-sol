int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int numRabbits(int* answers, int answersSize) {
    // เรียงลำดับคำตอบ
    qsort(answers, answersSize, sizeof(int), compare);
    
    int total = 0;
    int i = 0;
    
    while (i < answersSize) {
        int current = answers[i];
        int count = 0;
        
        // นับจำนวนกระต่ายที่บอกค่าเดียวกัน
        while (i < answersSize && answers[i] == current) {
            count++;
            i++;
        }
        
        // คำนวณจำนวนกระต่ายขั้นต่ำสำหรับสีนี้
        int group_size = current + 1;
        int groups = (count + group_size - 1) / group_size; // ceil(count / group_size) ปัดขึ้น
        total += groups * group_size;
    }
    
    return total;
}