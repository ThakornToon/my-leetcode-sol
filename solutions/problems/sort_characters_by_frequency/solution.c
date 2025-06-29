#define ASCII_SIZE 128

typedef struct {
    char character;
    int frequency;
} CharFrequency;

int compare(const void *a, const void *b) {
    return ((CharFrequency*)b)->frequency - ((CharFrequency*)a)->frequency; // เรียงความถี่มากไปน้อย
}

char* frequencySort(char* s) {
    int len = strlen(s);
    int frequencies[ASCII_SIZE] = {0};
    
    // นับความถี่ของแต่ละอักขระ
    for (int i = 0; i < len; i++) {
        frequencies[(int)s[i]]++;
    }
    
    // สร้างอาร์เรย์ของ CharFrequency
    CharFrequency* cf = malloc(ASCII_SIZE * sizeof(CharFrequency));
    int count = 0;
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (frequencies[i] > 0) {
            cf[count].character = (char)i;
            cf[count].frequency = frequencies[i];
            count++;
        }
    }
    
    // เรียงลำดับตามความถี่
    qsort(cf, count, sizeof(CharFrequency), compare);
    
    // สร้างสตริงผลลัพธ์
    char* result = malloc((len + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < cf[i].frequency; j++) {
            result[index++] = cf[i].character;
        }
    }
    result[index] = '\0';
    
    free(cf);
    return result;
}