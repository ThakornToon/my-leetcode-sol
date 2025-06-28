bool validUtf8(int* data, int dataSize) {
    int count = 0;
    for (int i = 0; i < dataSize; i++) {
        unsigned char c = data[i];
        if (count == 0) {
            if ((c >> 5) == 0x06) count = 1;
            else if ((c >> 4) == 0x0E) count = 2;
            else if ((c >> 3) == 0x1E) count = 3;
            else if ((c >> 7)) return false;
        } else {
            if ((c >> 6) != 0x02) return false;
            count--;
        }
    }
    return count == 0;
}