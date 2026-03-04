bool canReach(int* arr, int arrSize, int start) {
    if (arr[start] == 0) return true;
    
    // สร้าง queue
    int* queue = (int*)malloc(arrSize * sizeof(int));
    int front = 0, rear = 0;
    
    // visited array
    bool* visited = (bool*)calloc(arrSize, sizeof(bool));
    
    queue[rear++] = start;
    visited[start] = true;
    
    while (front < rear) {
        int current = queue[front++];
        
        // ลองเคลื่อนที่ไปทางขวา
        int next = current + arr[current];
        if (next < arrSize && !visited[next]) {
            if (arr[next] == 0) {
                free(queue);
                free(visited);
                return true;
            }
            visited[next] = true;
            queue[rear++] = next;
        }
        
        // ลองเคลื่อนที่ไปทางซ้าย
        next = current - arr[current];
        if (next >= 0 && !visited[next]) {
            if (arr[next] == 0) {
                free(queue);
                free(visited);
                return true;
            }
            visited[next] = true;
            queue[rear++] = next;
        }
    }
    
    free(queue);
    free(visited);
    return false;
}