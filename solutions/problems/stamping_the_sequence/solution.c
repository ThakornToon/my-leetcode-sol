/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* movesToStamp(char* stamp, char* target, int* returnSize) {
    int m = strlen(stamp);
    int n = strlen(target);
    
    int* result = (int*)malloc(n * sizeof(int));
    int resultIdx = 0;
    
    int totalChanged = 0; 
    
    while (totalChanged < n) {
        bool found = false;
        
        // ลองทุกตำแหน่ง
        for (int i = 0; i <= n - m; i++) {
            // ตรวจสอบว่า stamp match กับ target หรือไม่
            bool match = true;
            int newChanges = 0;
            
            for (int j = 0; j < m; j++) {
                if (target[i + j] != '?' && target[i + j] != stamp[j]) {
                    match = false;
                    break;
                }
                if (target[i + j] != '?') {
                    newChanges++;
                }
            }
            
            if (match && newChanges > 0) {
                // ปั๊ม stamp
                for (int j = 0; j < m; j++) {
                    if (target[i + j] != '?') {
                        target[i + j] = '?';
                        totalChanged++;
                    }
                }
                
                result[resultIdx++] = i;
                found = true;
                break;
            }
        }
        
        if (!found) {
            // ไม่สามารถปั๊มต่อได้
            break;
        }
    }
    
    // ตรวจว่าแก้ไขลำดับครบไหม
    if (totalChanged < n) { 
        free(result);
        *returnSize = 0;
        return NULL;
    }
    
    // Reverse ลำดับ
    for (int i = 0; i < resultIdx / 2; i++) {
        int temp = result[i];
        result[i] = result[resultIdx - 1 - i];
        result[resultIdx - 1 - i] = temp;
    }
    
    *returnSize = resultIdx;
    return result;
}