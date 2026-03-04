class Solution {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        boolean[] visited = new boolean[n];
        Stack<Integer> stack = new Stack<>();
        
        stack.push(start);
        
        while (!stack.isEmpty()) {
            int curr = stack.pop();
            
            if (visited[curr]) continue;
            
            if (arr[curr] == 0) return true;
            
            visited[curr] = true;
            
            int next = curr + arr[curr];
            if (next < n) {
                stack.push(next);
            }
            
            next = curr - arr[curr];
            if (next >= 0) {
                stack.push(next);
            }
        }
        
        return false;
    }
}