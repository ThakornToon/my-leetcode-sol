int minCut(char* s) {
    int size = strlen(s);
    bool** isPalin = (bool**)malloc(size * sizeof(bool*));
    for (int i = 0; i < size; i++) {
        isPalin[i] = (bool*)malloc(size * sizeof(bool));
        for (int j = 0; j < size; j++) {
            isPalin[i][j] = false;
        }
    }

    for (int i = 0; i < size; i++) {
        isPalin[i][i] = true;
    }
    for (int len = 2; len <= size; len++) {
        for (int start = 0; start <= size - len; start++) {
            int end = start + len - 1;
            if (s[start] == s[end]) {
                if (len == 2) {
                    isPalin[start][end] = true;
                } 
                else {
                    isPalin[start][end] = isPalin[start+1][end-1];
                }
            }
        }
    }


    int* cuts = (int*)malloc(size * sizeof(int));
    for (int end = 0; end < size; end++) {
        if (isPalin[0][end]) {
            cuts[end] = 0; // No cut needed if s[0..i] is a palindrome
        } 
        else {
            cuts[end] = end; // Max cuts possible (cut before every character)
            for (int start = 1; start <= end; start++) {
                if (isPalin[start][end]) {
                    if(cuts[end] > cuts[start - 1] + 1) {
                        cuts[end] = cuts[start - 1] + 1;
                    }
                }
            }
        }
    }


    int ans = cuts[size-1];
    free(cuts);
    for (int i = 0; i < size; i++) {
        free(isPalin[i]);
    }
    free(isPalin);
    return ans;
}