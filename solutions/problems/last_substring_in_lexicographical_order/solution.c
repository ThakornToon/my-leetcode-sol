int max(int a, int b) {
    return a > b ? a : b;
}

char* lastSubstring(char* s) {
    int n = strlen(s);      
    int i = 0;  // candidate 1
    int j = 1;  // candidate 2
    int k = 0;  // length compared
        
    while (j + k < n) {
        if (s[i + k] == s[j + k]) {
            k++;
            continue;
        }
        
        if (s[i + k] < s[j + k]) {
            // candidate j is better
            // i ต้องกระโดดอย่างน้อย k+1 หรือ j
            // fedfedgg -> fedf fedg
            // aaaac -> aaaac, aaac, aac ac ต้องพยายามข้ามให้ไกล
            // fedcbaaaaafedcg -> fedcba, fedcg
            // efg
            i = max(i + k + 1, j);
            j = i + 1;
        } else {
            // candidate i is better การบวก k จะข้ามส่วนที่ซ้ำเพื่อไม่ให้คิดซ้ำซ้อน
            // bbbbaceddddf -> bbbb bbba
            // fedfedaa -> fedf feda
            j = j + k + 1;
        }
        k = 0;
    }
        
    return s+i;
}