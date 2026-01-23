class Solution {
    public List<Integer> circularPermutation(int n, int start) {
int size = 1 << n;
        boolean[] visited = new boolean[size];
        List<Integer> result = new ArrayList<>(size);
        
        result.add(start);
        visited[start] = true;
        
        if (dfs(n, start, result, visited)) {
            return result;
        }
        
        return new ArrayList<>();  // ไม่เจอ (ไม่ควรเกิด)
    }
    
    private boolean dfs(int n, int current, List<Integer> result, boolean[] visited) {
        int size = 1 << n;
        
        if (result.size() == size) {
            // ตรวจสอบ circular condition
            int first = result.get(0);
            int last = result.get(result.size() - 1);
            int diff = first ^ last;
            return Integer.bitCount(diff) == 1;
        }
        
        // ลองเปลี่ยนแต่ละบิต
        for (int i = 0; i < n; i++) {
            int next = current ^ (1 << i);
            
            if (!visited[next]) {
                visited[next] = true;
                result.add(next);
                
                if (dfs(n, next, result, visited)) {
                    return true;
                }
                
                // backtrack
                result.remove(result.size() - 1);
                visited[next] = false;
            }
        }
        
        return false;
    }
}