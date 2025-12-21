int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int baseSatisfied = 0;
    
    // คำนวณลูกค้าที่พอใจตอนเจ้าของอารมณ์ดี
    for (int i = 0; i < customersSize; i++) {
        if (grumpy[i] == 0) {
            baseSatisfied += customers[i];
        }
    }
    
    // Sliding window เพื่อหาช่วง minutes ที่ดีที่สุด
    int maxAdditional = 0;
    int currentAdditional = 0;
    
    // เปลี่ยนช่วงที่ไม่พึงพอใจเป็นพึงพอใจ
    for (int i = 0; i < minutes; i++) {
        if (grumpy[i] == 1) {
            currentAdditional += customers[i];
        }
    }
    maxAdditional = currentAdditional;
    for (int i = minutes; i < customersSize; i++) {
        // Remove leftmost element
        if (grumpy[i - minutes] == 1) {
            currentAdditional -= customers[i - minutes];
        }

        // Add new element
        if (grumpy[i] == 1) {
            currentAdditional += customers[i];
        }

        maxAdditional = (currentAdditional > maxAdditional) ? currentAdditional : maxAdditional;
    }
    
    return baseSatisfied + maxAdditional;
}