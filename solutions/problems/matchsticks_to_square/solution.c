int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

bool backtrack(int* matchsticks, int matchsticksSize, int index, int* sides, int target) {
    if (index == matchsticksSize) {
        return sides[0] == target && sides[1] == target && sides[2] == target;
    }
    
    for (int i = 0; i < 4; i++) {
        if (sides[i] + matchsticks[index] > target) continue;
        if (i > 0 && sides[i] == sides[i-1]) continue;
        
        sides[i] += matchsticks[index];
        if (backtrack(matchsticks, matchsticksSize, index + 1, sides, target)) {
            return true;
        }
        sides[i] -= matchsticks[index];
    }
    
    return false;
}

bool makesquare(int* matchsticks, int matchsticksSize) {    
    int total = 0;
    for (int i = 0; i < matchsticksSize; i++) {
        total += matchsticks[i];
    }
    
    if (total % 4 != 0) return false;
    int target = total / 4;
    
    qsort(matchsticks, matchsticksSize, sizeof(int), compare); // มากไปน้อย
    int sides[4] = {0};
    
    return backtrack(matchsticks, matchsticksSize, 0, sides, target);
}