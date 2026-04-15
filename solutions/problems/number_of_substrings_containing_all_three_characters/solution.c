int numberOfSubstrings(char* s) {
    int n = strlen(s);
    int count[3] = {0};  // นับ a,b,c
    int left = 0;
    int result = 0;
    
    for (int right = 0; right < n; right++) {
        // เพิ่มตัวอักษรที่ตำแหน่ง right
        count[s[right] - 'a']++;
        
        // เมื่อมีครบทุกตัว ให้เลื่อน left จนกว่าจะไม่ครบ
        while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
            // ทุก substring ที่เริ่มจาก left ไปจนถึง right ใช้ได้
            result += n - right;
            
            // เลื่อน left ออก
            count[s[left] - 'a']--;
            left++;
        }
    }
    
    return result;
}