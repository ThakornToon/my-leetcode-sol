int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int maximizeSquareHoleArea(int n, int m, int* hBars, int hBarsSize, int* vBars, int vBarsSize) {
    // เรียงตำแหน่ง bars
    qsort(hBars, hBarsSize, sizeof(int), compare);
    qsort(vBars, vBarsSize, sizeof(int), compare);
    
    int hConsecutive = 1;
    int maxH = hBarsSize > 0;
    int vConsecutive = 1;
    int maxV = vBarsSize > 0;

    for (int i = 0; i < hBarsSize - 1; i++) {
        if (hBars[i] + 1 == hBars[i + 1]) {
            hConsecutive++;
        } else {
            hConsecutive = 1;
        }

        if (hConsecutive > maxH) {
            maxH = hConsecutive;
        }
    }
    if (hConsecutive > maxH) {
        maxH = hConsecutive;
    }

    for (int i = 0; i < vBarsSize - 1; i++) {
        if (vBars[i] + 1 == vBars[i + 1]) {
            vConsecutive++;
        } else {
            vConsecutive = 1;
        }

        if (vConsecutive > maxV) {
            maxV = vConsecutive;
        }
    }
    if (vConsecutive > maxV) {
        maxV = vConsecutive;
    }

    int side = (maxH > maxV) ? maxV : maxH;
    return  (side + 1) * (side + 1);
}