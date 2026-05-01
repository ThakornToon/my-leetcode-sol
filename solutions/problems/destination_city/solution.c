char* destCity(char*** paths, int pathsSize, int* pathsColSize) {
    // เก็บ source ทั้งหมด
    char** sources = (char**)malloc(pathsSize * sizeof(char*));
    int sourceCount = 0;
    
    for (int i = 0; i < pathsSize; i++) {
        sources[sourceCount++] = paths[i][0];
    }
    
    // ตรวจสอบ destination
    for (int i = 0; i < pathsSize; i++) {
        char* to = paths[i][1];
        int isSource = 0;
        for (int j = 0; j < sourceCount; j++) {
            if (strcmp(sources[j], to) == 0) {
                isSource = 1;
                break;
            }
        }
        if (!isSource) {
            free(sources);
            return to;
        }
    }
    
    free(sources);
    return NULL;
}