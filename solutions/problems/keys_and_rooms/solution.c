bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));
    int* stack = (int*)malloc(roomsSize * sizeof(int));
    int top = -1;
    
    // Start from room 0
    stack[++top] = 0;
    visited[0] = true;
    int count = 1;
    
    while (top >= 0) {
        int current = stack[top--];
        
        for (int i = 0; i < roomsColSize[current]; i++) {
            int key = rooms[current][i];
            if (!visited[key]) {
                visited[key] = true;
                count++;
                stack[++top] = key;
            }
        }
    }
    
    free(visited);
    free(stack);
    return count == roomsSize;
}