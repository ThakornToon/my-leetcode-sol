/*
arr = [1, 2, 3, 4]

เราต้องการหา OR ของทุก subarray:
[1], [1,2], [1,2,3], [1,2,3,4]
[2], [2,3], [2,3,4]
[3], [3,4]
[4]
*/
#define MAX_UNIQUE 30000  // ประมาณ 30 * 1000
int subarrayBitwiseORs(int* arr, int arrSize) {
    // ใช้สอง arrays สำหรับ cur และ next
    int* cur = (int*)malloc(MAX_UNIQUE * sizeof(int));
    int* next = (int*)malloc(MAX_UNIQUE * sizeof(int));
    bool* seen = (bool*)calloc(1 << 30, sizeof(bool));  // hash แบบง่าย
    
    int cur_size = 0, next_size = 0;
    int result_count = 0;
    
    for (int i = 0; i < arrSize; i++) {
        int num = arr[i];
        next_size = 0;
        
        // เพิ่มตัวมันเอง
        next[next_size++] = num;
        if (!seen[num]) {
            seen[num] = true;
            result_count++;
        }
        
        // รวมกับค่าที่มีใน cur
        for (int j = 0; j < cur_size; j++) {
            int new_val = cur[j] | num;
            if (j == 0 || new_val != next[next_size - 1]) {
                next[next_size++] = new_val;
                if (!seen[new_val]) {
                    seen[new_val] = true;
                    result_count++;
                }
            }
        }
        
        // update cur
        int* temp = cur;
        cur = next;
        next = temp;
        cur_size = next_size;
    }
    
    free(cur);
    free(next);
    free(seen);
    
    return result_count;
}