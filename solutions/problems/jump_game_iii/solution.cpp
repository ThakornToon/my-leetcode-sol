class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if (arr[start] == 0) return true;
        
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            // ไปทางขวา
            int next = curr + arr[curr];
            if (next < n && !visited[next]) {
                if (arr[next] == 0) return true;
                visited[next] = true;
                q.push(next);
            }
            
            // ไปทางซ้าย
            next = curr - arr[curr];
            if (next >= 0 && !visited[next]) {
                if (arr[next] == 0) return true;
                visited[next] = true;
                q.push(next);
            }
        }
        
        return false;
    }
};