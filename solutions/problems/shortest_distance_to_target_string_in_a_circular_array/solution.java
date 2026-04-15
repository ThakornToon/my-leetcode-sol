class Solution {
    public int closestTarget(String[] words, String target, int startIndex) {
        int n = words.length;
        int minDist = Integer.MAX_VALUE;
        boolean found = false;
        
        for (int i = 0; i < n; i++) {
            if (words[i].equals(target)) {
                found = true;
                int forward = (i - startIndex + n) % n;
                int backward = (startIndex - i + n) % n;
                int dist = Math.min(forward, backward);
                minDist = Math.min(minDist, dist);
            }
        }
        
        return found ? minDist : -1;
    }
}