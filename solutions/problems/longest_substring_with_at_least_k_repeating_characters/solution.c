#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int longestSubstring(char* s, int k) {
    int max_len = 0;
    int n = strlen(s);
    
    for (int unique_target = 1; unique_target <= 26; unique_target++) { // พิจารณาว่ามีตัวอักษรที่แตกต่างกี่ตัว
        int freq[26] = {0};
        int left = 0, unique = 0, count_at_least_k = 0;
        // Sliding Window ใช้ Two pointer
        for (int right = 0; right < n; right++) { // เพิ่มขนาดหน้าต่างไปทางขวา
            int idx = s[right] - 'a'; 
            if (freq[idx] == 0) unique++; // หากพบตัวอักษรตัวใหม่
            freq[idx]++; // นับจำนวนตัวอักษรในหน้าต่างนั้น
            if (freq[idx] == k) count_at_least_k++; // นับจำนวนตัวอักษรที่มีความถี่ = k 
            
            while (unique > unique_target) { // จนกว่ามีตัวอักษรที่แตกต่างตามที่ต้องการ เราจะลดขนาดหน้าต่างจากทางซ้าย
                int left_idx = s[left] - 'a';
                if (freq[left_idx] == k) count_at_least_k--; // หากตัวอักษรที่มีจำนวน = k ถูกนำออก
                freq[left_idx]--; // ลบตัวอักษร
                if (freq[left_idx] == 0) unique--; // กรณีที่ถูกลบทำให้ไม่เหลือตัวอักษรนั้นอยู่
                left++;
            }
            
            if (unique == unique_target && unique == count_at_least_k) { // มีตัวอักษร unique_target ตัวที่มีจำนวน >= k
                max_len = MAX(max_len, right - left + 1); // ขนาดหน้าต่างที่มากที่สุด
            }
        }
    }
    return max_len;
}