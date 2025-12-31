int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int equalSubstring(char* s, char* t, int maxCost) {
    int n = strlen(s);
    int maxLength = 0;
    int currentCost = 0;
    int left = 0;
    
    for (int right = 0; right < n; right++) {
        // คำนวณค่าใช้จ่าย
        int cost = abs(s[right] - t[right]);
        currentCost += cost;
        
        // ขยับหน้าต่างซ้ายถ้าเกิน budget
        while (currentCost > maxCost) {
            currentCost -= abs(s[left] - t[left]);
            left++;
        }
        
        // อัปเดตความยาวสูงสุด
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;

}