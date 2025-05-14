char* convert(char* s, int numRows) {
    if (numRows == 1 || strlen(s) <= numRows) {
        return strdup(s);
    }
    char** table = (char**)calloc(numRows ,sizeof(char*));
    for (int row = 0; row < numRows; row++) {
        table[row] = (char*)calloc(strlen(s)+1, sizeof(char));
    }
    int index = 0;
    int column = 0;
    while (index < strlen(s)) {
        int row = 0;
        while (row < numRows && index < strlen(s)) {
            table[row][column] = s[index];
            index++;
            row++;
        }
        row = numRows - 2;
        column++;
        while (row > 0 && index < strlen(s)) {
            table[row][column] = s[index];
            column++;
            index++;
            row--;
        }
    }
    char* ans = (char*)calloc(strlen(s)+1, sizeof(char));
    index = 0;
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col <= column; col++) {
            if (table[row][col] != 0) {
                ans[index] = table[row][col];
                index++;
            }
        }
    }
    for (int row = 0; row < numRows; row++) {
        free(table[row]);
    }
    free(table);
    ans[index] = '\0';
    return ans;
}