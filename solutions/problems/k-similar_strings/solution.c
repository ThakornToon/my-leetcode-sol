int min(int A, int B) {
    return A < B ? A : B;
}

void swap(char** A, int i, int j) {
    char temp = (*A)[i];
    (*A)[i] =  (*A)[j];
    (*A)[j] = temp;
}

int dfs(char** A, char** B, int i) {
    int size = strlen(*A);
    if (i == size) return 0;
    if ((*A)[i] == (*B)[i]) return dfs(A, B, i + 1);
        
    int minSwaps = INT_MAX;
        
    for (int j = i + 1; j < size; j++) {
        if ((*A)[j] == (*B)[i] && (*A)[j] != (*B)[j]) {
            swap(A, i, j);

            int result = 1 + dfs(A, B, i + 1);
            minSwaps = min(minSwaps, result);
                
            swap(A, i, j);  // backtrack

            // Greedy: ถ้า direct swap
            if ((*A)[i] == (*B)[j]) {
                break;
            }
        }
    }
    
    return minSwaps;
}


int kSimilarity(char* s1, char* s2) {
    return dfs(&s1, &s2, 0);
}
