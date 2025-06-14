int minimumAddedCoins(int* coins, int coinsSize, int target) {
    int* cnt = (int*)calloc(target + 1, sizeof(int)); // ดูว่ามีค่านั้นหรือยัง
    for (int i = 0; i < coinsSize; i++){
        int x = coins[i];
        if (x <= target) {
            cnt[x]++; // จำนวนเหรียญค่านั้นๆ
        }
    }
    int added = 0;
    if (cnt[1] == 0) {
        cnt[1] = 1;
        added++;
    }
    long long reach = cnt[1]; // ค่าที่ไปไกลสุดตอนนี้
    for (int i = 2; i <= target; i++) {
        if (cnt[i] == 0 && reach < i) { // หากเหรียญค่านั้นยังไม่มีจะเพิ่มมา แต่ถ้ามีอยู่แล้วจะช่วยขยายขอบเขตโดยไม่ต้องเพิ่มเอง
            added++;
            cnt[i] = 1;
        }
        reach += cnt[i] * i; // จะเลื่อนไปเรื่อยๆ 1 +2 +3 +4 ... ระวังกรณีเหรียญมีค่าซ้ำได้

        if (reach >= target) {
            break;
        }
    }
    free(cnt);
    return added;
}