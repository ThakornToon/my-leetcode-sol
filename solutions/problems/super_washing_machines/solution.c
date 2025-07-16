int max(int a, int b) {
    return (a >= b) ? a : b;
}
int findMinMoves(int* machines, int machinesSize) {
    int total = 0;
    for (int i = 0; i < machinesSize; i++) {
        total += machines[i];
    }
    if (total % machinesSize != 0) {
        return -1;
    }
    int target = total / machinesSize;
    int result = 0;
    int sum = 0;

    for (int i = 0; i < machinesSize; i++) {
        int diff = machines[i] - target; // จำนวนเสื้อผ้าขั้นต่ำที่เครื่องนี้ต้องส่งออก
        sum += diff; // ดูว่าเครื่องนี้จะต้องได้รับ(-)หรือส่งออก(+)ผ้ากี่ครั้ง เพื่อส่งไปทางซ้าย(-) หรือ รับจากทางซ้ายแล้วค่อยส่งไปทางขวา(+)
        result = max(result, max(abs(sum), diff));
    }

    return result;
}