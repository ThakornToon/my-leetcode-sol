/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node* visited[101];

struct Node* dfs(struct Node* s) {
    if (!s) return NULL;

    // ตรวจสอบว่าโหนดนี้ถูกสร้างไปแล้วหรือไม่
    if (visited[s->val]) {
        return visited[s->val];
    }

    // จองหน่วยความจำสำหรับโหนดใหม่และอาเรย์ neighbors
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = s->val;
    clone->numNeighbors = s->numNeighbors;
    clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * s->numNeighbors);

    visited[s->val] = clone;

    for (int i = 0; i < s->numNeighbors; i++) {
        clone->neighbors[i] = dfs(s->neighbors[i]);
    }

    return clone;
}

struct Node *cloneGraph(struct Node *s) {
    if (!s) return NULL;
    memset(visited, 0, sizeof(visited));
    return dfs(s);
}