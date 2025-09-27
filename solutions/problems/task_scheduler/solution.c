int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int leastInterval(char* tasks, int tasksSize, int n) {    
    int count[26] = {0};
    
    // นับความถี่ของแต่ละ task
    for (int i = 0; i < tasksSize; i++) {
        count[tasks[i] - 'A']++;
    }
    
    // เรียงลำดับความถี่จากมากไปน้อย
    qsort(count, 26, sizeof(int), compare);
    
    // หาจำนวน task ที่มีความถี่สูงสุด
    int max_count = count[0];
    int num_max = 1;
    
    for (int i = 1; i < 26; i++) {
        if (count[i] == max_count) {
            num_max++;
        } else {
            break;
        }
    }
    
    // คำนวณเวลาขั้นต่ำ
    int min_time = (max_count - 1) * (n + 1) + num_max;
    
    // ต้องไม่น้อยกว่าจำนวน task ทั้งหมด
    return (min_time > tasksSize) ? min_time : tasksSize;
}