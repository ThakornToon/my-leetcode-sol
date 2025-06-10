int compare(const void *a, const void *b) {
    char ab[21], ba[21];
    
    sprintf(ab, "%d%d", *(int*)a, *(int*)b);
    sprintf(ba, "%d%d", *(int*)b, *(int*)a);
    
    return strcmp(ba, ab); 
}
char* largestNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    if(nums[0] == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        strcpy(result, "0");
        return result;
    }
    
    int totalLength = 0;
    for(int i = 0; i < numsSize; i++) {
        char buffer[11];
        sprintf(buffer, "%d", nums[i]);
        totalLength += strlen(buffer);
    }
    
    char* result = (char*)malloc((totalLength + 1) * sizeof(char));
    result[0] = '\0';
    for(int i = 0; i < numsSize; i++) {
        char buffer[11];
        sprintf(buffer, "%d", nums[i]);
        strcat(result, buffer);
    }
    
    return result;
}