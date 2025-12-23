int compare(const void* a, const void* b) {
    int* item1 = *(int**)a;
    int* item2 = *(int**)b;
    return item2[0] - item1[0]; // เรียงจากมากไปน้อย
}

int largestValsFromLabels(int* values, int valuesSize, int* labels, int labelsSize, int numWanted, int useLimit) {
    int n = valuesSize;
    
    // สร้าง array ของ [value, label]
    int** items = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        items[i] = (int*)malloc(2 * sizeof(int));
        items[i][0] = values[i];
        items[i][1] = labels[i];
    }
    
    // เรียงตาม value จากมากไปน้อย
    qsort(items, n, sizeof(int*), compare);
    
    // ใช้ hashmap แบบง่ายนับจำนวน items ที่เลือกในแต่ละ label
    // เนื่องจาก label มีค่าสูงสุด 20000
    int labelCount[20001] = {0};
    
    int sum = 0;
    int selected = 0;
    
    for (int i = 0; i < n && selected < numWanted; i++) {
        int value = items[i][0];
        int label = items[i][1];
        
        if (labelCount[label] < useLimit) {
            sum += value;
            labelCount[label]++;
            selected++;
        }
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i < n; i++) {
        free(items[i]);
    }
    free(items);
    
    return sum;
}