/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int count_bits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** result = (char**)malloc(720 * sizeof(char*));
    *returnSize = 0;
    
    for (int h = 0; h < 12; h++) {
        for (int m = 0; m < 60; m++) {
            if (count_bits(h) + count_bits(m) == turnedOn) {
                char* time = (char*)malloc(6 * sizeof(char)); // เก็บรูปแบบ "H:MM"
                sprintf(time, "%d:%02d", h, m);
                result[(*returnSize)++] = time;
            }
        }
    }
    
    return result;
}