class Solution {
public:
    int countArrangement(int n) {
        vector<bool> visited(n + 1, false);
        int count = 0;
        backtrack(n, 1, visited, count);
        return count;
    }
    void backtrack(int n, int pos, vector<bool>& visited, int& count) {
        if (pos > n) {
            count++;
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
};