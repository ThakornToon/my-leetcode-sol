#define MAX_DECK_SIZE 10000

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool hasGroupsSizeX(int* deck, int deckSize) {
    // เก็บความถี่ของไพ่แต่ละใบ
    int freq[MAX_DECK_SIZE] = {0};
    int maxVal = 0;
    
    for (int i = 0; i < deckSize; i++) {
        freq[deck[i]]++;
        if (deck[i] > maxVal) maxVal = deck[i];
    }
    
    // หา GCD ของความถี่ทั้งหมด
    int g = 0;
    for (int i = 0; i <= maxVal; i++) {
        if (freq[i] > 0) {
            if (g == 0) {
                g = freq[i];
            } else {
                g = gcd(g, freq[i]);
            }
        }
    }
    
    return g >= 2;
}