int minNumberOfFrogs(char* croakOfFrogs) {
    int n = strlen(croakOfFrogs);
    if (n % 5 != 0) return -1;
    
    int count[5] = {0};  // c,r,o,a,k
    int activeFrogs = 0;
    int maxFrogs = 0;
    
    for (int i = 0; i < n; i++) {
        char c = croakOfFrogs[i];
        
        switch (c) {
            case 'c':
                count[0]++;
                activeFrogs++;
                if (activeFrogs > maxFrogs) maxFrogs = activeFrogs;
                break;
            case 'r':
                if (count[0] <= count[1]) return -1;
                count[1]++;
                break;
            case 'o':
                if (count[1] <= count[2]) return -1;
                count[2]++;
                break;
            case 'a':
                if (count[2] <= count[3]) return -1;
                count[3]++;
                break;
            case 'k':
                if (count[3] <= count[4]) return -1;
                count[4]++;
                activeFrogs--;
                break;
            default:
                return -1;
        }
    }
    
    // ตรวจสอบว่าทุกเสียงจบสมบูรณ์
    if (count[0] != count[4] || count[1] != count[4] || 
        count[2] != count[4] || count[3] != count[4]) {
        return -1;
    }
    
    return maxFrogs;
}