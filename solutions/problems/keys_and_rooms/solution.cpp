class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        
        dfs(rooms, 0, visited);
        
        // Check if all rooms are visited
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
    
private:
    void dfs(vector<vector<int>>& rooms, int room, vector<bool>& visited) {
        visited[room] = true;
        
        for (int key : rooms[room]) {
            if (!visited[key]) {
                dfs(rooms, key, visited);
            }
        }
    }
};