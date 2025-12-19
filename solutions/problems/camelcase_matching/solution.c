/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* camelMatch(char** queries, int queriesSize, char* pattern, int* returnSize) {
    bool* answer = (bool*)malloc(queriesSize * sizeof(bool));
    *returnSize = queriesSize;
    
    // ฟังก์ชัน helper ตรวจสอบแต่ละ query
    bool matches(char* query, char* pattern) {
        int i = 0, j = 0;
        int qlen = strlen(query);
        int plen = strlen(pattern);
        
        while (i < qlen) {
            if (j < plen && query[i] == pattern[j]) {
                i++;
                j++;
            } else if (islower(query[i])) {
                i++;
            } else {
                return false;
            }
        }
        
        return j == plen;
    }
    
    for (int idx = 0; idx < queriesSize; idx++) {
        answer[idx] = matches(queries[idx], pattern);
    }
    
    return answer;
}