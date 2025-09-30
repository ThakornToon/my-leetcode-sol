int maximumSwap(int num) {
    char s[10];
    sprintf(s, "%d", num);
    int n = strlen(s);
    
    // เก็บ index ของตัวเลขที่ใหญ่ที่สุดจากขวา
    int maxRight[10];
    maxRight[n-1] = n-1;
    
    for (int i = n-2; i >= 0; i--) {
        if (s[i] > s[maxRight[i+1]]) {
            maxRight[i] = i;
        } else {
            maxRight[i] = maxRight[i+1];
        }
    }
    
    // หาตำแหน่งแรกที่ตัวเลขไม่ใช่ค่าสูงสุดจากขวา
    for (int i = 0; i < n; i++) {
        if (s[i] < s[maxRight[i]]) {
            // สลับตัวเลข
            char temp = s[i];
            s[i] = s[maxRight[i]];
            s[maxRight[i]] = temp;
            break;
        }
    }
    
    return atoi(s);
}