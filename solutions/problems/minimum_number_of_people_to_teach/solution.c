#define MAX_PEOPLE 501
#define MAX_LANG 501

int minimumTeachings(int n, int** languages, int languagesSize, int* languagesColSize, int** friendships, int friendshipsSize, int* friendshipsColSize) {
    int m = languagesSize;
    
    // สร้าง matrix ความรู้ภาษา: knows[person][lang]
    bool** knows = (bool**)malloc((m + 1) * sizeof(bool*));
    for (int i = 0; i <= m; i++) {
        knows[i] = (bool*)calloc(n + 1, sizeof(bool));
    }
    
    // เติมข้อมูลภาษาที่แต่ละคนรู้
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < languagesColSize[i]; j++) {
            int lang = languages[i][j];
            knows[i + 1][lang] = true;
        }
    }
    
    // หาคนที่ต้องสอน
    bool* needTeach = (bool*)calloc(m + 1, sizeof(bool));
    int needTeachCount = 0;
    
    for (int f = 0; f < friendshipsSize; f++) {
        int u = friendships[f][0];
        int v = friendships[f][1];
        
        // ตรวจสอบว่ามีภาษากลางหรือไม่
        bool canTalk = false;
        for (int lang = 1; lang <= n; lang++) {
            if (knows[u][lang] && knows[v][lang]) {
                canTalk = true;
                break;
            }
        }
        
        if (!canTalk) {
            if (!needTeach[u]) {
                needTeach[u] = true;
                needTeachCount++;
            }
            if (!needTeach[v]) {
                needTeach[v] = true;
                needTeachCount++;
            }
        }
    }
    
    if (needTeachCount == 0) {
        for (int i = 0; i <= m; i++) free(knows[i]);
        free(knows);
        free(needTeach);
        return 0;
    }
    
    // นับว่าคนใน needTeach รู้ภาษาอะไรบ้าง
    int* knowCount = (int*)calloc(n + 1, sizeof(int));
    
    for (int person = 1; person <= m; person++) {
        if (!needTeach[person]) continue;
        
        for (int lang = 1; lang <= n; lang++) {
            if (knows[person][lang]) {
                knowCount[lang]++;
            }
        }
    }
    
    // หาภาษาที่คนใน needTeach รู้มากที่สุด
    int maxKnown = 0;
    for (int lang = 1; lang <= n; lang++) {
        if (knowCount[lang] > maxKnown) {
            maxKnown = knowCount[lang];
        }
    }
    
    int result = needTeachCount - maxKnown;
    
    // Cleanup
    for (int i = 0; i <= m; i++) free(knows[i]);
    free(knows);
    free(needTeach);
    free(knowCount);
    
    return result;
}