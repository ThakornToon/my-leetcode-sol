#define MAX_TYPES 100000

int totalFruit(int* fruits, int fruitsSize) {
    int* count = (int*)calloc(MAX_TYPES, sizeof(int));
    int distinct = 0;
    int left = 0, max_len = 0;
    
    for (int right = 0; right < fruitsSize; right++) {
        // เพิ่ม count ของผลไม้ประเภทปัจจุบัน
        if (count[fruits[right]] == 0) {
            distinct++;
        }
        count[fruits[right]]++;
        
        // ถ้ามีมากกว่า 2 ประเภท
        while (distinct > 2) {
            count[fruits[left]]--;
            if (count[fruits[left]] == 0) {
                distinct--;
            }
            left++;
        }
        
        // อัพเดตความยาวสูงสุด
        int window_len = right - left + 1;
        if (window_len > max_len) {
            max_len = window_len;
        }
    }
    
    free(count);
    return max_len;
}