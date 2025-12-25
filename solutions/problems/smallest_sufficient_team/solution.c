/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* smallestSufficientTeam(char** req_skills, int req_skillsSize, char*** people, int peopleSize, int* peopleColSize, int* returnSize) {
    int n = req_skillsSize;
    int m = peopleSize;
    
    // แปลงทักษะของแต่ละคนเป็น bitmask
    int* peopleMask = (int*)calloc(m, sizeof(int));
    for (int i = 0; i < m; i++) {
        // ทำ mask ว่ามี skill ไหนใน req บ้าง
        for (int j = 0; j < peopleColSize[i]; j++) {
            for (int k = 0; k < n; k++) {
                if (strcmp(people[i][j], req_skills[k]) == 0) {
                    peopleMask[i] |= (1 << k);
                    break;
                }
            }
        }
    }
    
    int targetMask = (1 << n) - 1; // 11..1
    int dpSize = 1 << n;
    
    // dp[mask] = คนน้อยที่สุดที่จะได้ mask นี้
    int* dp = (int*)malloc(dpSize * sizeof(int));
    for (int i = 0; i < dpSize; i++) {
        dp[i] = INT_MAX / 2;
    }
    dp[0] = 0;
    
    // parentMask[mask] = mask ก่อนหน้า
    // parentPerson[mask] = คนที่เพิ่มมาเพื่อให้ได้ mask ปัจจุบันจาก prev_mask ก่อนหน้า
    int* parentMask = (int*)malloc(dpSize * sizeof(int));
    int* parentPerson = (int*)malloc(dpSize * sizeof(int));
    for (int i = 0; i < dpSize; i++) {
        parentMask[i] = -1;
        parentPerson[i] = -1;
    }
    
    // DP
    for (int i = 0; i < m; i++) {
        int personMask = peopleMask[i];
        if (personMask == 0) continue;
        
        // คิดทุกกรณีจากบนลงล่างเพื่อหากรณีที่ดีที่สุดและไม่เลือกคนซ้ำ
        for (int mask = targetMask; mask >= 0; mask--) {
            int newMask = mask | personMask;
            // dp[mask | peopleMask[i]] = min(dp[mask] + 1)
            if (dp[mask] + 1 < dp[newMask]) {
                dp[newMask] = dp[mask] + 1;
                parentMask[newMask] = mask;
                parentPerson[newMask] = i;
            }
        }
    }
    
    // Backtrack คิดย้อนกลับ
    int* result = (int*)malloc(m * sizeof(int));
    int resultSize = 0;
    int mask = targetMask;
    
    while (mask > 0) {
        int personIdx = parentPerson[mask];
        result[resultSize++] = personIdx;
        mask = parentMask[mask];
    }
    
    *returnSize = resultSize;
    
    // Resize array
    result = realloc(result, resultSize * sizeof(int));
    
    free(peopleMask);
    free(dp);
    free(parentMask);
    free(parentPerson);
    
    return result;
}