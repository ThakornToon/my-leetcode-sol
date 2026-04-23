class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        
        int suffixSum = 0;
        int result = 0;
        
        for (int i = satisfaction.length - 1; i >= 0; i--) {
            suffixSum += satisfaction[i];
            if (suffixSum <= 0) break;
            result += suffixSum;
        }
        
        return result;
    }
}