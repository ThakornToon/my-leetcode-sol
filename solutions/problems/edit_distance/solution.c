int findMin(int n1, int n2, int n3) {
    int min = n1;
    if (n2 < min) min = n2;
    if (n3 < min) min = n3;
    return min; 
}

int minDistance(char* word1, char* word2) {
    int row = strlen(word1);
    int col = strlen(word2);
    if (row == 0 || col == 0) {
        if (row > col) {
            return row;
        }
        else {
            return col;
        }
    }
    if (strcmp(word1, word2) == 0) {
        return 0;
    }
    int* prev = (int*)malloc((col+1) * sizeof(int));
    int* curr = (int*)malloc((col+1) * sizeof(int));
    for (int j = 0; j <= col; j++) {
        prev[j] = j;
    }
    for (int i = 1; i <= row; i++) {
        curr[0] = i;
        for (int j = 1; j <= col; j++) {
            if (word1[i-1] == word2[j-1]) {
                curr[j] = prev[j - 1];
            }
            else { //else if (word1[i-1] != word2[j-1])
                curr[j] = findMin(prev[j - 1], curr[j - 1], prev[j]) + 1;
            }
        }

        for (int k = 0; k <= col; k++) {
            prev[k] = curr[k];
            curr[k] = 0;
        }
    }
    int ans = prev[col];
    free(prev);
    free(curr);
    return ans;
}