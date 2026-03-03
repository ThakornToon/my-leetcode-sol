/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes) {
    // ขนาดกลุ่มที่เป็นไปได้คือ 1 ถึง groupSizesSize (n)
    int maxSize = groupSizesSize;
    
    // สร้าง 2D array ชั่วคราวเพื่อเก็บคนตามขนาดกลุ่ม
    // groups[size][index] = person id
    int** groups = (int**)malloc((maxSize + 1) * sizeof(int*));
    int* groupCounts = (int*)calloc(maxSize + 1, sizeof(int));
    
    // จองพื้นที่สำหรับแต่ละขนาดกลุ่ม
    for (int i = 1; i <= maxSize; i++) {
        groups[i] = (int*)malloc(maxSize * sizeof(int));
    }
    
    // นับจำนวนกลุ่มล่วงหน้าเพื่อจองพื้นที่ result
    // จำนวนกลุ่ม = ผลรวมของ (จำนวนคนที่มี size เท่ากัน / size)
    int totalGroups = 0;
    int* sizeCounts = (int*)calloc(maxSize + 1, sizeof(int));
    for (int i = 0; i < groupSizesSize; i++) {
        sizeCounts[groupSizes[i]]++;
    }
    for (int size = 1; size <= maxSize; size++) {
        totalGroups += sizeCounts[size] / size;
    }
    free(sizeCounts);
    
    // จองพื้นที่สำหรับ result
    int** result = (int**)malloc(totalGroups * sizeof(int*));
    *returnColumnSizes = (int*)malloc(totalGroups * sizeof(int));
    *returnSize = 0;
    
    // วนลูปผ่านแต่ละคน
    for (int i = 0; i < groupSizesSize; i++) {
        int size = groupSizes[i];
        
        // เพิ่มคนเข้า groups ตามขนาด
        groups[size][groupCounts[size]] = i;
        groupCounts[size]++;
        
        // ถ้ามีคนครบตามขนาดกลุ่มแล้ว
        if (groupCounts[size] == size) {
            // สร้างกลุ่มใหม่
            int* newGroup = (int*)malloc(size * sizeof(int));
            for (int j = 0; j < size; j++) {
                newGroup[j] = groups[size][j];
            }
            
            result[*returnSize] = newGroup;
            (*returnColumnSizes)[*returnSize] = size;
            (*returnSize)++;
            
            // รีเซ็ต count
            groupCounts[size] = 0;
        }
    }
    
    // คืนหน่วยความจำ
    for (int i = 1; i <= maxSize; i++) {
        free(groups[i]);
    }
    free(groups);
    free(groupCounts);
    
    return result;
}