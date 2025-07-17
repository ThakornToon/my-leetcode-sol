void dfs(int city, int n, int** isConnected, bool* visited) {
    visited[city] = true;
    for (int neighbor = 0; neighbor < n; ++neighbor) {
        if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
            dfs(neighbor, n, isConnected, visited);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    int provinces = 0;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, n, isConnected, visited);
            provinces++;
        }
    }
    
    return provinces;
}