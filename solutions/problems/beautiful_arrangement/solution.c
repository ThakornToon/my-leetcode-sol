void backtrack(int n, int pos, bool* visited, int* count) {
    if (pos > n) {
        (*count)++;
        return;
    }
    
    for (int num = 1; num <= n; num++) {
        if (!visited[num] && (num % pos == 0 || pos % num == 0)) {
            visited[num] = true;
            backtrack(n, pos + 1, visited, count);
            visited[num] = false;
        }
    }
}

int countArrangement(int n) {
    bool* visited = (bool*)calloc(n + 1, sizeof(bool));
    int count = 0;
    backtrack(n, 1, visited, &count);
    free(visited);
    return count;
}